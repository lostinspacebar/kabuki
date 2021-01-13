/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_stream.hpp
 * @brief   Audio file interface.
 */

#ifndef KABUKI_AUDIO_STREAM_H_
#define KABUKI_AUDIO_STREAM_H_

namespace kabuki::audio
{
    class audio_stream
    {
    public:
        audio_stream() {}
        virtual ~audio_stream() {}

        virtual long sample_rate() = 0;
        virtual uint8_t num_channels() = 0;
        virtual size_t length() = 0;
        virtual size_t read(char *buffer, size_t offset, size_t count) = 0;
    };
}

#endif