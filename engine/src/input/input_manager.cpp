/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    input_manager.hpp
 * @brief   Centralized input manager. Handles keyboard, mouse and gamepad 
 *          events and notifies any subscribers.
 */

#include "input/input_manager.hpp"

namespace kabuki::input
{
    input_manager::input_manager()
    {
        _keyboard = std::make_shared<keyboard_state>();
    }

    void input_manager::process_event(SDL_Event event)
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                _keyboard->process_event(event);
                break;
        }
    }
}