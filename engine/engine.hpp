/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.hpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

#ifndef KABUKI_ENGINE_H_
#define KABUKI_ENGINE_H_

#include "utility/log.hpp"
#include "window.hpp"

namespace kabuki
{
    class engine
    {
    public:
        static engine& initialize(const char *title, int width, int height)
        {
            static engine singleton(title, width, height);
            return singleton;
        }

        // A single engine frame / think iteration.
        void tick();

        // Gets whether the engine is still alive and running.
        bool is_running()
        {
            return _is_running;
        }

        // Cleanup
        ~engine();

    private:
        engine(const char *title, int width, int height);
        
        bool _is_running = true;
        std::unique_ptr<window> _main_window;
        std::unique_ptr<utility::log> _log;
    };
}

#endif