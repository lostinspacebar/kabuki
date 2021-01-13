/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    audio_manager.cpp
 * @brief   Centralized audio manager. Allows for adding of audio emitters 
 *          around the 3D world.
 */

#include "audio/audio_manager.hpp"
#include "audio/audio_utils.hpp"

namespace kabuki::audio
{
    audio_manager::audio_manager() : engine_component("audio_manager")
    {
        log()->info("Opening default audio device.");

        // Clear any errors
        alGetError();

        // Open default device
        _open_al_device = alcOpenDevice(NULL);
        if(!_open_al_device)
        {
            log()->error("Could not open default device.");
            throw;
        }
        _open_al_context = alcCreateContext(_open_al_device, NULL);
        alcMakeContextCurrent(_open_al_context);

        // Set distance model
        alDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);
        if(openal_has_error())
        {
            log()->error("Couldn't set distance model.");
        }

        // Setup listener
        _listener.reset(new audio_listener());
        _listener->set_position(0, 0, 0);
    }

    audio_emitter *audio_manager::create_emitter(std::string emitter_id)
    {
        _emitters.insert(std::make_pair(emitter_id, std::unique_ptr<audio_emitter>(new audio_emitter(emitter_id))));
        return emitter_by_id(emitter_id);
    }

    audio_manager::~audio_manager()
    {
        log()->info("Cleaning up audio resources.");
        alcMakeContextCurrent(NULL);
        alcDestroyContext(_open_al_context);
        alcCloseDevice(_open_al_device);
    }

    void audio_manager::tick(double elapsed, double timeScale)
    {
        // Update audio listener
        alListener3f(AL_POSITION, _listener->position().x, _listener->position().y, _listener->position().z);
        alListener3f(AL_VELOCITY, 0, 0, 0);

        // Tick all emitters
        for(const auto& emitter : _emitters)
        {
            emitter.second->tick();
        }
    }
}