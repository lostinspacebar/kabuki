/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    keyboard.hpp
 * @brief   Global keyboard state
 */

#include "input_codes.hpp"
#include <SDL.h>

namespace kabuki::input
{
    class keyboard_state
    {
    public:
        void process_event(SDL_Event event);
        bool is_key_pressed(keyboard_key key) { return _key_pressed[key]; }
    private:
        keyboard_key sdl2_keycode_to_key(SDL_Keycode code);
        bool _key_pressed[keyboard_key::NUMBER_OF_KEYS];
    };
}