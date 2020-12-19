/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    input_codes.hpp
 * @brief   Codes for buttons, keys etc. on various types of inputs we handle.
 */

#ifndef KABUKI_INPUT_CODES_H
#define KABUKI_INPUT_CODES_H

namespace kabuki::input
{
    enum keyboard_key
    {
        KEY_UNKNOWN,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        KEY_0,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        KEY_SPACE,
        KEY_ENTER,
        KEY_LSHIFT,
        KEY_LCTRL,
        KEY_LALT,
        KEY_RSHIFT,
        KEY_RCTRL,
        KEY_RALT,
        KEY_TAB,
        KEY_TILDE,
        KEY_ARROW_UP,
        KEY_ARROW_DOWN,
        KEY_ARROW_LEFT,
        KEY_ARROW_RIGHT,
        NUMBER_OF_KEYS
    };

    enum mouse_button
    {
        LEFT,
        RIGHT,
        MIDDLE
    };
}

#endif