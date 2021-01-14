/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.cpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

#include "engine.hpp"
#include "audio/audio_emitter.hpp"
#include <SDL_opengl.h>

namespace kabuki
{
    engine::engine(std::string title, int width, int height, uint32_t window_flags) : engine_component("engine")
    {
        log()->info("KABUKI GAME ENGINE 0.1");
        log()->info("----------------------");
        log()->info("Initializing OpenGL...");

        // Start measuring time elapsed
        _startup_time = std::chrono::steady_clock::now();

        // Initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            log()->error("Could not init SDL: %s\n", SDL_GetError());
            throw;
        }

        // Setup flags for OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        // Setup input manager
        _input_manager = std::make_unique<input::input_manager>();

        // Setup audio manager
        _audio_manager = std::make_unique<audio::audio_manager>();

        // Create main stage
        _stage = std::make_unique<stage>(_input_manager.get(), _audio_manager.get());

        // Create the main window
        _main_window = std::unique_ptr<window>(new window(title, width, height, window_flags));

        fps_frames = 0;
        fps_last_elapsed = 0;

        audio::audio_emitter *emitter = _audio_manager->create_emitter("test_audio");
        emitter->load("test.wav");
        emitter->play(true);
        emitter->set_position(0, 0, 0);

        // All done
        log()->info("Engine ready.");
    }

    engine::~engine()
    {
        log()->info("Shutting down SDL.");
        SDL_Quit();
    }

    static float pos = 0;

    void engine::tick()
    {
        double elapsed = elapsed_seconds();
        SDL_Event sdl_event;
        if(SDL_PollEvent(&sdl_event))
        {
            // Let the input manager handle any input events
            _input_manager->process_event(sdl_event);

            if(_input_manager->keyboard()->is_key_pressed(kabuki::input::keyboard_key::KEY_W))
            {
                log()->info("away");
                pos += 0.1;
                if(pos > 20)
                {
                    pos = 20;
                }
                _audio_manager->emitter_by_id("test_audio")->set_position(pos, pos, 0);
            }
            else if(_input_manager->keyboard()->is_key_pressed(kabuki::input::keyboard_key::KEY_S))
            {
                log()->info("close");
                pos -= 0.1;
                if(pos < -20)
                {
                    pos = -20;
                }
                _audio_manager->emitter_by_id("test_audio")->set_position(pos, pos, 0);
            }

            // Handle any engine level events.
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                    _is_running = false;
                    break;
            }
        }

        // Move events on stage forward
        _stage->tick(elapsed, 1.0);

        // Tick audio manager
        _audio_manager->tick(elapsed, 1.0);

        fps_frames++;
        if(elapsed - fps_last_elapsed >= 1.0)
        {
            log()->info("FPS {0}", fps_frames);
            fps_frames = 0;
            fps_last_elapsed = elapsed;
        }

        // Show stuff on screen
        _main_window.get()->present();
    }

    double engine::elapsed_seconds()
    {
        auto now = std::chrono::steady_clock::now();
        return (double)((now - _startup_time).count()) / 1000000000.0;
    }
}