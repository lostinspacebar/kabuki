/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_emitter.cpp
 * @brief   An emitter in 3D space that can play audio.
 */

#include "audio/audio_emitter.hpp"
#include "audio/ogg_file.hpp"
#include "utility/path_utils.hpp"
#include "audio/audio_utils.hpp"

#include <stdexcept>

namespace kabuki::audio
{
    audio_emitter::audio_emitter(std::string emitter_id) : entity("audio_emitter_" + emitter_id)
    {
        _id = emitter_id;
        _is_source_valid = false;
    }

    void audio_emitter::load(std::string file_path)
    {
        _audio_stream = load_from_file(file_path);
        
        // Setup OpenAL buffer and source
        // For files, we will just load everything in for now. 
        // TODO: Make this stream from disk for large files later
        alGenBuffers((ALuint)1, &_openal_buffer);
        if(openal_has_error())
        {
            log()->error("Could not generate OpenAL buffer for audio file: {0}", file_path);
            throw std::runtime_error("Could not generate OpenAL buffer");
        }
        ALenum format = _audio_stream->num_channels() > 1 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;
        
        // Allocate memory for the audio data
        // TODO: Is there a non malloc way to do this?
        _audio_data = (char *) malloc(_audio_stream->length());
        if(_audio_data == 0)
        {
            log()->error("Could not allocate buffer of size {0}", _audio_stream->length());
            throw std::runtime_error("Could not allocate buffer in memory");
        }

        // Load all data from the ogg file
        size_t bytes_read = 0;
        while(bytes_read < _audio_stream->length())
        {
            size_t chunk_length = _audio_stream->read(_audio_data, bytes_read, 4096);
            if(chunk_length == 0)
            {
                // EOF
                break;
            }
            bytes_read += chunk_length;
        }
        if(bytes_read != _audio_stream->length())
        {
            log()->error("Could not read all data from file: {0}. Expected {1}, Read {2}.", file_path, _audio_stream->length(), bytes_read);
            throw std::runtime_error("Could not read all data from file.");
        }

        // Load AL buffer with data read from file
        alBufferData(_openal_buffer, format, _audio_data, _audio_stream->length(), _audio_stream->sample_rate());
        if(openal_has_error())
        {
            log()->error("Could not load audio data into OpenAL buffer: {0}", file_path);
            throw std::runtime_error("Could not load audio data into OpenAL buffer.");
        }

        _audio_loaded = true;
    }

    bool audio_emitter::play(bool loop)
    {
        if(is_playing())
        {
            log()->warn("Emitter is already playing.");
            return false;
        }

        if(_audio_loaded == false)
        {
            log()->error("No audio loaded. Will not play.");
            return false;
        }

        if(_num_openal_sources_used >= _max_openal_sources)
        {
            log()->error("No sources left to use.");
            return false;
        }

        // Generate OpenAL source to use for playback
        alGenSources((ALuint) 1, &_openal_source);
        if(openal_has_error())
        {
            log()->error("Could not generate source to play audio with.");
            return false;
        }
        _num_openal_sources_used++;
        _is_source_valid = true;

        // Bind source to buffer
        alSourcei(_openal_source, AL_BUFFER, _openal_buffer);
        if(openal_has_error())
        {
            log()->error("Could not bind buffer {0} to source: {1}", _openal_source, _openal_buffer);
            return false;
        }
        alSourcei(_openal_source, AL_LOOPING, loop ? 1 : 0);
        if(openal_has_error())
        {
            log()->error("Could not set LOOPING to {0} for source {1}", loop, _openal_source);
            return false;
        }

        // Play audio
        alSourcePlay(_openal_source);
        if(openal_has_error())
        {
            log()->error("Could not start playing source {0}", _openal_source);
            return false;
        }

        return true;
    }

    void audio_emitter::pause()
    {
        if(_is_source_valid)
        {
            alSourcePause(_openal_source);
            if(openal_has_error())
            {
                log()->error("Could not pause playing source {0}", _openal_source);
            }
        }
    }

    void audio_emitter::stop()
    {
        if(_is_source_valid)
        {
            alSourceStop(_openal_source);
            alDeleteSources(1, &_openal_source);
            if(openal_has_error())
            {
                log()->error("Could not stop playing source {0}", _openal_source);
            }
        }
        _num_openal_sources_used--;
        _is_source_valid = false;
    }

    void audio_emitter::rewind()
    {
        if(_is_source_valid)
        {
            alSourceRewind(_openal_source);
            if(openal_has_error())
            {
                log()->error("Could not rewind source {0}", _openal_source);
            }
        }
    }

    void audio_emitter::on_tick()
    {
        if(_is_source_valid)
        {
            int source_state;
            alGetSourcei(_openal_source, AL_SOURCE_STATE, &source_state);
            if(source_state == AL_STOPPED)
            {
                // Source is done playing. Send it back to the pool.
                stop();
            }
        }
    }

    void audio_emitter::on_set_position()
    {
        if(_is_source_valid)
        {
            alSource3f(_openal_source, AL_POSITION, position().x, position().y, position().z);
            log()->info("Moving source to {0}, {1}, {2}", position().x, position().y, position().z);
            if(openal_has_error())
            {
                log()->error("Could not set position on source {0} to {1}, {2}, {3}", _openal_source, position().x, position().y, position().z);
            }
        }
    }

    void audio_emitter::on_set_rotation()
    {

    }

    audio_emitter::~audio_emitter()
    {
        std::free(_audio_data);
        if(_audio_loaded)
        {
            alDeleteBuffers(1, &_openal_buffer);
        }
    }

    std::unique_ptr<audio_stream> audio_emitter::load_from_file(std::string file_path)
    {
        if(utility::path::has_extension(file_path, ".ogg"))
        {
            return std::make_unique<ogg_file>(file_path);
        }
        return nullptr;
    }

    uint8_t audio_emitter::_num_openal_sources_used = 0;
}