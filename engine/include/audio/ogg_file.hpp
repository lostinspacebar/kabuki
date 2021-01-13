/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    ogg_file.hpp
 * @brief   An Ogg Vorbis file. This provides easy ways to load whole .ogg 
 *          files or stream chunks in.
 */

#ifndef KABUKI_AUDIO_OGG_FILE_H_
#define KABUKI_AUDIO_OGG_FILE_H_

#include "utility/log.hpp"
#include "audio/audio_stream.hpp"
#include <vorbis/vorbisfile.h>

#include <fstream>
#include <memory>

namespace kabuki::audio
{
    class ogg_file : public audio_stream
    {
    public:
        ogg_file(std::string file_path);
        
        long sample_rate() override { return _sample_rate; }
        uint8_t num_channels() override { return _num_channels; }
        size_t length() override { return _file_size; }
        size_t read(char *buffer, size_t offset, size_t count) override;

        ~ogg_file() {}
    private:
        std::unique_ptr<utility::log> _log;
        OggVorbis_File _ogg;
        std::ifstream _file_stream;
        uint8_t _num_channels;
        size_t _file_size;
        long _sample_rate;
    };
}

#endif