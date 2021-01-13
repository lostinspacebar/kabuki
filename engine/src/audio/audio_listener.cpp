/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_listener.cpp
 * @brief   An listener in 3D space that hears audio played by audio_emitter
 *          instances. There is generally only 1 instance of this 
 *          audio_listener active at any time in the world.
 */

#include "audio/audio_listener.hpp"

namespace kabuki::audio
{
    audio_listener::audio_listener() : entity("audio_listener")
    {
        
    }
}