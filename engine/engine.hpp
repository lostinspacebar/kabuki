/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.hpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

#ifndef KABUKI_ENGINE_H_
#define KABUKI_ENGINE_H_

#include "engine_component.hpp"
#include "window.hpp"

namespace kabuki
{
    class engine : public engine_component
    {
    public:
        /**
         * Simplified initialization of the engine. The main window is set to
         * the desktop native resolution and is made fullscreen.
         */
        static engine &initialize(const char *title)
        {
            return initialize(title, 0, 0, window_flags::FULLSCREEN);
        }

        /**
         * Initialize and return an instance to the engine. This should only 
         * be called once, although calling it multiple times will return
         * the same instance.
         * 
         * Both width and height can be set to 0 to automatically choose the 
         * current desktop resolution as the engine resolution.
         * 
         * @param title         Title of the main window acted on by the engine
         * @param width         Width of the window in pixels
         * @param height        Height of the window in pixels
         * @param window_flags  Some extra flags for window creation
         */
        static engine& initialize(const char *title, int width, int height, uint32_t window_flags)
        {
            static engine singleton(title, width, height, window_flags);
            return singleton;
        }

        /**
         * Have the engine go through a single think cycle or "frame".
         */
        void tick();

        /**
         * Gets whether the engine is currently running.
         */
        bool is_running()
        {
            return _is_running;
        }

        // Cleanup
        ~engine();

    private:
        engine(const char *title, int width, int height, uint32_t window_flags);
        
        bool _is_running = true;
        std::unique_ptr<window> _main_window;
    };
}

#endif