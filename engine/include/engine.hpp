/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.hpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

#ifndef KABUKI_ENGINE_H_
#define KABUKI_ENGINE_H_

#include "input/input_manager.hpp"
#include "audio/audio_manager.hpp"
#include "engine_component.hpp"
#include "stage.hpp"
#include "window.hpp"

#include <chrono>

namespace kabuki
{
    class engine : public engine_component
    {
    public:
        /**
         * Simplified initialization of the engine. The main window is set to
         * the desktop native resolution and is made fullscreen.
         */
        static engine &initialize(std::string title)
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
        static engine& initialize(std::string title, int width, int height, uint32_t window_flags)
        {
            static engine singleton(title, width, height, window_flags);
            return singleton;
        }

        /**
         * Gets the input manager for the running engine.
         */
        inline input::input_manager *input_manager() const { return _input_manager.get(); }

        /**
         * Gets the main stage where all the entities in the engine perform.
         */
        inline stage *main_stage() const { return _stage.get(); }

        /**
         * Have the engine go through a single think cycle or "frame".
         */
        void tick();

        /**
         * Gets whether the engine is currently running.
         */
        bool is_running() { return _is_running; }

        /**
         * Number of seconds since the engine was started.
         */
        double elapsed_seconds();

        // Cleanup
        ~engine();

    private:
        engine(std::string title, int width, int height, uint32_t window_flags);
        
        bool _is_running = true;
        std::unique_ptr<stage> _stage;
        std::unique_ptr<input::input_manager> _input_manager;
        std::unique_ptr<audio::audio_manager> _audio_manager;
        std::unique_ptr<window> _main_window;
        std::chrono::time_point<std::chrono::steady_clock> _startup_time;

        // FPS
        int fps_frames;
        double fps_last_elapsed;
    };
}

#endif