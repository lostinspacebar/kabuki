/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_emitter.hpp
 * @brief   An emitter in 3D space that can play audio.
 */

#ifndef KABUKI_AUDIO_EMITTER_H_
#define KABUKI_AUDIO_EMITTER_H_

#include "entity.hpp"
#include "audio/audio_stream.hpp"

#include <AL/al.h>
#include <string>
#include <memory>

namespace kabuki::audio
{
    class audio_emitter : public entity
    {
    public:

        /**
         * Loads the audio file at the specified path into the emitter. If the 
         * emitter was playing audio, it is stopped before the file is loaded.
         * 
         * @param file_path     Path to audio file.
         */
        void load(std::string file_path);

        /**
         * Starts playing the loaded audio file. If the emitter is already 
         * playing audio, this is ignored.
         * 
         * @param loop          If true, the audio file is looped while playing.
         */
        bool play(bool loop);

        /**
         * Pauses the audio playback. If the emitter is currently paused or
         * stopped, this is ignored.
         */
        void pause();

        /**
         * Stops the audio playback. If the emitter is currently paused or
         * stopped, this is ignored.
         */
        void stop();

        /**
         * Rewinds the audio playback. If the emitter is currently playing
         * audio, this will continue to play audio from the beginning.
         */
        void rewind();
        
        /**
         * Gets whether the emitter is currently playing audio. Returns false
         * if paused or stopped.
         */
        inline bool is_playing()
        {
            if(_is_source_valid)
            {
                int source_state;
                alGetSourcei(_openal_source, AL_SOURCE_STATE, &source_state);
                return source_state == AL_PLAYING;
            }
            return false;    
        }

        virtual void on_tick() override;
        virtual void on_set_position() override;
        virtual void on_set_rotation() override;

        ~audio_emitter();
        
    private:
        friend class audio_manager;
        audio_emitter(std::string emitter_id);
        

        static std::unique_ptr<audio_stream> load_from_file(std::string file_path);
        static uint8_t _num_openal_sources_used;
        static const uint8_t _max_openal_sources = 16;

        std::string _id;
        ALuint _openal_source;
        ALuint _openal_buffer;
        bool   _audio_loaded;
        bool   _is_source_valid;

        std::unique_ptr<audio_stream> _audio_stream;
        char *_audio_data;
    };
}

#endif