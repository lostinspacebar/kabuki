/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    window.hpp
 * @brief   Engine window 
 */

#ifndef KABUKI_WINDOW_H_
#define KABUKI_WINDOW_H_

#include "utility/log.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace kabuki
{
    class window
    {
    public:
        window(GLFWwindow* glfw_win)
        {
            _glfw_window = glfw_win;
        }

        GLFWwindow *get_glfw_window()
        {
            return _glfw_window;
        }

        bool is_close_pending()
        {
            return glfwWindowShouldClose(_glfw_window);
        }

        void present()
        {
            glfwSwapBuffers(_glfw_window);
        }

    private:
        utility::log *_log;
        GLFWwindow* _glfw_window;
    };
}

#endif