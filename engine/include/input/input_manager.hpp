/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    input_manager.hpp
 * @brief   Centralized input manager. Handles keyboard, mouse and gamepad 
 *          events and notifies any subscribers.
 */

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
        inline const keyboard_state &keyboard() const { return *_keyboard; }

    private:
        std::unique_ptr<keyboard_state> _keyboard;
    };
}