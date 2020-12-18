/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    window.cpp
 * @brief   Window wrapper. One of these is created when the engine is started.
 */

#include "window.hpp"
#include <GL/glew.h>
#include <SDL_opengl.h>

namespace kabuki
{
    window::window(const char *title, int width, int height, uint32_t window_flags) : engine_component("window")
    {
        Uint32 flags = SDL_WINDOW_OPENGL;

        SDL_DisplayMode dm;
        SDL_GetDesktopDisplayMode(0, &dm);

        if(width == 0 && height == 0)
        {
            width = dm.w;
            height = dm.h;
        }
        if(window_flags & window_flags::FULLSCREEN)
        {
            if(dm.w == width && dm.h == height)
            {
                flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
            }
            else
            {
                flags |= SDL_WINDOW_FULLSCREEN;
            }
        }
        if(window_flags & window_flags::BORDERLESS)
        {
            flags |= SDL_WINDOW_BORDERLESS;
        }
        if(window_flags & window_flags::RESIZABLE)
        {
            flags |= SDL_WINDOW_RESIZABLE;
        }
        _sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(_sdl_window == NULL)
        {
            _log->error("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            throw;
        }

        _sdl_gl_context = SDL_GL_CreateContext(_sdl_window);
        make_current();
    }

    window::~window()
    {
        _log->info("Cleaning up window resources.");
        SDL_GL_DeleteContext(_sdl_gl_context);
        SDL_DestroyWindow(_sdl_window);
    }

    void window::make_current()
    {
        int screen_width, screen_height;

        // Make the window's context the current one we are drawing to.
        SDL_GL_MakeCurrent(_sdl_window, _sdl_gl_context);
        
        // Setup GLEW and load all OpenGL functions
        glewExperimental = GL_TRUE;
        if (GLEW_OK != glewInit()) 
        { 
            _log->error("Could not initialize GLEW.");
            throw; 
        }
        
        SDL_GetWindowSize(_sdl_window, &screen_width, &screen_height);
        glViewport(0, 0, screen_width, screen_height);
    }

    void window::present()
    {
        SDL_GL_SwapWindow(_sdl_window);
    }
}