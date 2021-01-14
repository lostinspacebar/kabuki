/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    wav_file.hpp
 * @brief   A WAV file. This provides easy ways to load whole .wav files or 
 *          stream them in.
 */

#ifndef KABUKI_AUDIO_WAV_FILE_H_
#define KABUKI_AUDIO_WAV_FILE_H_

#include "utility/log.hpp"
#include "audio/audio_stream.hpp"

#include <fstream>
#include <memory>

namespace kabuki::audio
{
    class wav_file : public audio_stream
    {
    public:
        wav_file(std::string file_path);
        
        long bits_per_sample() override { return _bits_per_sample; }
        long sample_rate() override { return _sample_rate; }
        int num_channels() override { return _num_channels; }
        size_t length() override { return _data_size; }
        size_t read(char *buffer, size_t offset, size_t count) override;

        ~wav_file() {}
    private:
        std::unique_ptr<utility::log> _log;
        std::ifstream _file_stream;
        int _num_channels;
        size_t _data_size;
        long _sample_rate;
        int _bits_per_sample;
    };
}

#endif