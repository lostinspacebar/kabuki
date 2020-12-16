/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine.cpp
 * @brief   Main engine class. This is the entry point into Kabuki.
 */

// This is needed so GLEW loads the static library instead of the DLL
#define GLEW_STATIC

#include "engine.hpp"

namespace kabuki
{
    engine::engine()
    {
        _log = new utility::log("engine");
        _log->info("KABUKI GAME ENGINE 0.1");
        _log->info("----------------------");
        _log->info("Initializing OpenGL...");

        // Initialize GLFW
        if (!glfwInit())
        {
            _log->error("GLFW could not be initialized.");
            throw;
        }

        _log->info("Engine ready.");
    }

    engine::~engine()
    {
        glfwTerminate();
    }

    window *engine::create_window(const char *title, int width, int height)
    {
        GLFWwindow *glfw_win = glfwCreateWindow(width, height, title, nullptr, nullptr);

        int screen_width, screen_height;
        glfwGetFramebufferSize(glfw_win, &screen_width, &screen_height); 
        if (nullptr == glfw_win) 
        { 
            _log->error("Could not create GLFW window.");
            glfwTerminate();
            throw;
        }
        glfwMakeContextCurrent(glfw_win);

        glewExperimental = GL_TRUE;
        if (GLEW_OK != glewInit()) 
        { 
            _log->error("Could not initialize GLEW.");
            throw;
        }
        glViewport(0, 0, screen_width, screen_height);

        return new window(glfw_win);
    }

    void engine::think()
    {
        // Swap buffers for the current window
        
        
        // Process any pending events.
        glfwPollEvents();
    }
}