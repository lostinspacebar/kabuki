/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    ogg_file.cpp
 * @brief   An Ogg Vorbis file. This provides easy ways to load whole .ogg 
 *          files or stream chunks in.
 */

#include "audio/ogg_file.hpp"

namespace kabuki::audio
{
    static size_t ifs_read(void *dest, size_t size, size_t num, void *ifs)
    {
        auto& stream = *static_cast<std::ifstream *>(ifs);
        stream.read(static_cast<char *>(dest), size * num);

        return stream.gcount();
    }

    static int ifs_seek(void *ifs, ogg_int64_t offset, int origin) 
    {
        static const std::vector<std::ios_base::seekdir> seekDirections
        {
            std::ios_base::beg, std::ios_base::cur, std::ios_base::end
        };

        auto& stream = *static_cast<std::ifstream *>(ifs);
        stream.seekg(offset, seekDirections.at(origin));
        stream.clear();
        return 0;
    }

    static long ifs_tell(void *ifs)
    {
        auto& stream = *static_cast<std::ifstream *>(ifs);
        const auto position = stream.tellg();
        assert(position >= 0);
        return static_cast<long>(position);
    }

    static int ifs_close(void *ifs)
    {
        auto& stream = *static_cast<std::ifstream *>(ifs);
        stream.close();

        return 0;
    }

    ogg_file::ogg_file(std::string file_path) : audio_stream(), 
        _file_stream(file_path.c_str(), std::ifstream::binary)
    {
        _log = utility::log::create("ogg_file");

        ov_callbacks callbacks { ifs_read, ifs_seek, ifs_close, ifs_tell };
        int result = ov_open_callbacks(&_file_stream, &_ogg, nullptr, 0, callbacks);
        if(result != 0)
        {
            _log->error("Could not open ogg vorbis file: {0}", file_path);
            throw std::runtime_error("Could not open ogg file.");
        }

        vorbis_info *ogg_info = ov_info(&_ogg, -1);
        _sample_rate = ogg_info->rate;
        _num_channels = ogg_info->channels;
        _file_size = ov_pcm_total(&_ogg, -1) * _num_channels * 2;
    }

    size_t ogg_file::read(char *buffer, size_t offset, size_t count)
    {
        // TODO: do we need to expose this bitstream data?
        int bitstream;
        return ov_read(&_ogg, buffer + offset, count, 0, 2, 1, &bitstream);
    }

}