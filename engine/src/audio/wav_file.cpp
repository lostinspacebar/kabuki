/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    wav_file.cpp
 * @brief   A WAV file. This provides easy ways to load whole .wav files or 
 *          stream them in.
 */

#include "audio/wav_file.hpp"

namespace kabuki::audio
{
    struct wav_header
    {
        char                riff_header[4];
        unsigned long       file_size;
        char                wave_header[4];

        char                fmt_header[4];
        unsigned long       fmt_info_size;
        unsigned short      audio_format;
        unsigned short      num_channels;
        unsigned long       sample_rate;
        unsigned long       byte_rate;
        unsigned short      block_align;
        unsigned short      bits_per_sample;

        char                data_header[4];
        unsigned long       data_size;
    };

    wav_file::wav_file(std::string file_path) : audio_stream(), 
        _file_stream(file_path.c_str(), std::ifstream::binary)
    {
        wav_header header;
        _file_stream.read((char *) &header, sizeof(wav_header));
        _sample_rate = header.sample_rate;
        _data_size = header.data_size;
        _num_channels = header.num_channels;
        _bits_per_sample = header.bits_per_sample;
    }

    size_t wav_file::read(char *buffer, size_t offset, size_t count)
    {
        _file_stream.read(buffer + offset, count);
        return _file_stream.gcount();
    }
}