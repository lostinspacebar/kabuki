/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_manager.hpp
 * @brief   Centralized audio manager. Allows for adding of audio emitters 
 *          around the 3D world.
 */

#ifndef KABUKI_AUDIO_MANAGER_H_
#define KABUKI_AUDIO_MANAGER_H_

#include "engine_component.hpp"
#include "audio_listener.hpp"
#include "audio_emitter.hpp"

#include <map>
#include <memory>
#include <glm/glm.hpp>
#include <AL/al.h>
#include <AL/alc.h>

namespace kabuki::audio
{
    class audio_manager : public engine_component
    {
    public:
        audio_manager();

        /**
         * Gets the main audio listener for the engine. This should ideally be placed
         * next to the main camera in the world.
         */
        const audio_listener *listener() { return _listener.get(); }

        /**
         * Creates an audio emitter with the specified ID. ID has to be unique
         * and can be used later to retrieve this emitter.
         * 
         * @param emitter_id    Unique ID for this audio emitter
         */
        audio_emitter *create_emitter(std::string emitter_id);

        /**
         * Gets an audio emitters with the specified ID, if one exists.
         * 
         * @param    emitter_id    ID of audio emitter to retrieve
         * @return   Audio emitter with the specified ID, or nullptr if none found
         */
        inline audio_emitter *emitter_by_id(std::string emitter_id) const 
        { 
            auto it = _emitters.find(emitter_id);
            if(it != _emitters.end())
            {
                return it->second.get();
            }
            return nullptr;
        }

        /**
         * Process any audio events or requests. This is called 
         * every engine::tick.
         */
        void tick(double elapsed, double timeScale);

        ~audio_manager();

    private:
        std::unique_ptr<audio_listener> _listener;
        std::map<std::string, std::unique_ptr<audio_emitter>> _emitters;
        ALCdevice *_open_al_device;
        ALCcontext *_open_al_context;
    };
}

#endif