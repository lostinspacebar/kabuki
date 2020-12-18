/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    window.hpp
 * @brief   Engine window 
 */

// This is needed so GLEW loads the static library instead of the DLL
#define GLEW_STATIC

#ifndef KABUKI_WINDOW_H_
#define KABUKI_WINDOW_H_

#include "utility/log.hpp"
#include <SDL.h>

namespace kabuki
{
    class window
    {
    public:

        /**
         * Makes this window the current one being drawn to.
         */
        void make_current();

        /**
         * Update the contents of the window with what's been drawn to its back buffers so far.
         */
        void present();

        // Clean up
        ~window();

    private:
        friend class engine;

        /**
         * Private constructor.
         * 
         * @param title     Title for the window
         * @param width     Width of the window in pixels
         * @param height    Height of the window in pixels
         */
        window(const char *title, int width, int height);

        // Underlying SDL window handle.
        SDL_Window *_sdl_window;

        // Underlying SDL OpenGL context
        SDL_GLContext _sdl_gl_context;

        // Log
        std::unique_ptr<utility::log> _log;
    };
}

#endif