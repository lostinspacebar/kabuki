/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_listener.hpp
 * @brief   An listener in 3D space that hears audio played by audio_emitter
 *          instances. There is generally only 1 instance of this 
 *          audio_listener active at any time in the world.
 */

#ifndef KABUKI_AUDIO_LISTENER_H_
#define KABUKI_AUDIO_LISTENER_H_

#include "entity.hpp"

namespace kabuki::audio
{
    class audio_listener : public entity
    {
    public:
        
        
    private:
        friend class audio_manager;
        audio_listener();
        
    };
}

#endif