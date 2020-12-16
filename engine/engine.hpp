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

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace kabuki
{
    class engine
    {
    public:
        engine();
        ~engine();
        window *create_window(const char *title, int width, int height);
        void think();

    private:
        utility::log *_log;
    };
}

#endif