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
    engine::engine(const char *title, int width, int height)
    {
        _log = utility::log::create("engine");
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

        // Create the main window
        _main_window = std::unique_ptr<window>(new window(title, width, height));

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