/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    input_manager.hpp
 * @brief   Centralized input manager. Handles keyboard, mouse and gamepad 
 *          events and notifies any subscribers.
 */

#ifndef KABUKI_INPUT_MANAGER_H_
#define KABUKI_INPUT_MANAGER_H_

#include "input/keyboard_state.hpp"
#include <memory>

namespace kabuki::input
{
    class input_manager
    {
    public:
        input_manager();
        
        /**
         * Process any pending input events.
         */
        void process_event(SDL_Event event);

        /**
         * Get the current keyboard state.
         */
        inline const keyboard_state *keyboard() const { return _keyboard.get(); }

    private:
        std::unique_ptr<keyboard_state> _keyboard;
    };
}

#endif