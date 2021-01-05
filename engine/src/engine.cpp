/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.cpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

#include "engine.hpp"
#include <SDL_opengl.h>

namespace kabuki
{
    engine::engine(const char *title, int width, int height, uint32_t window_flags) : engine_component("engine")
    {
        _log->info("KABUKI GAME ENGINE 0.1");
        _log->info("----------------------");
        _log->info("Initializing OpenGL...");

        // Initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            _log->error("Could not init SDL: %s\n", SDL_GetError());
            throw;
        }

        // Setup flags for OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        // Setup input manager
        _input_manager = std::make_unique<input::input_manager>();

        // Create main stage
        _stage = std::make_unique<stage>(_input_manager.get());

        // Create the main window
        _main_window = std::unique_ptr<window>(new window(title, width, height, window_flags));

        // All done
        _log->info("Engine ready.");
    }

    engine::~engine()
    {
        _log->info("Shutting down SDL.");
        SDL_Quit();
    }

    void engine::tick()
    {
        SDL_Event sdl_event;
        if(SDL_PollEvent(&sdl_event))
        {
            // Let the input manager handle any input events
            _input_manager->process_event(sdl_event);

            // Move events on stage forward
            _stage->tick();

            // Handle any engine level events.
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                    _is_running = false;
                    break;
            }
        }

        _main_window.get()->present();
    }
}