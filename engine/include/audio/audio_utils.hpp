/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    ogg_file.hpp
 * @brief   An Ogg Vorbis file. This provides easy ways to load whole .ogg 
 *          files or stream chunks in.
 */

#include <AL/al.h>
#include <AL/alc.h>

#ifndef KABUKI_AUDIO_UTILS_H
#define KABUKI_AUDIO_UTILS_H

namespace kabuki::audio
{
    inline static bool openal_has_error()
    {
       return alGetError() != AL_NO_ERROR;
    }
}

#endif