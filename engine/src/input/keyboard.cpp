/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    keyboard.hpp
 * @brief   Global keyboard state
 */
#include "input/keyboard_state.hpp"

namespace kabuki::input
{
    void keyboard_state::process_event(SDL_Event event)
    {
        keyboard_key key = sdl2_keycode_to_key(event.key.keysym.sym);
        if(key != KEY_UNKNOWN)
        {
            _key_pressed[key] = (event.type == SDL_KEYDOWN);
        }
    }

    keyboard_key keyboard_state::sdl2_keycode_to_key(SDL_Keycode code)
    {
        switch(code)
        {
            case SDLK_a:
                return KEY_A;
            case SDLK_b:
                return KEY_B;
            case SDLK_c:
                return KEY_C;
            case SDLK_d:
                return KEY_D;
            case SDLK_e:
                return KEY_E;
            case SDLK_f:
                return KEY_F;
            case SDLK_g:
                return KEY_G;
            case SDLK_h:
                return KEY_H;
            case SDLK_i:
                return KEY_I;
            case SDLK_j:
                return KEY_J;
            case SDLK_k:
                return KEY_K;
            case SDLK_l:
                return KEY_L;
            case SDLK_m:
                return KEY_M;
            case SDLK_n:
                return KEY_N;
            case SDLK_o:
                return KEY_O;
            case SDLK_p:
                return KEY_P;
            case SDLK_q:
                return KEY_Q;
            case SDLK_r:
                return KEY_R;
            case SDLK_s:
                return KEY_S;
            case SDLK_t:
                return KEY_T;
            case SDLK_u:
                return KEY_U;
            case SDLK_v:
                return KEY_V;
            case SDLK_w:
                return KEY_W;
            case SDLK_x:
                return KEY_X;
            case SDLK_y:
                return KEY_Y;
            case SDLK_z:
                return KEY_Z;
            case SDLK_0:
                return KEY_0;
            case SDLK_1:
                return KEY_1;
            case SDLK_2:
                return KEY_2;
            case SDLK_3:
                return KEY_3;
            case SDLK_4:
                return KEY_4;
            case SDLK_5:
                return KEY_5;
            case SDLK_6:
                return KEY_6;
            case SDLK_7:
                return KEY_7;
            case SDLK_8:
                return KEY_8;
            case SDLK_9:
                return KEY_9;
            case SDLK_SPACE:
                return KEY_SPACE;
            case SDLK_RETURN:
            case SDLK_KP_ENTER:
                return KEY_ENTER;
            case SDLK_LSHIFT:
                return KEY_LSHIFT;
            case SDLK_LCTRL:
                return KEY_LCTRL;
            case SDLK_LALT:
                return KEY_LALT;
            case SDLK_RSHIFT:
                return KEY_RSHIFT;
            case SDLK_RCTRL:
                return KEY_RCTRL;
            case SDLK_RALT:
                return KEY_RALT;
            case SDLK_TAB:
                return KEY_TAB;
            case SDLK_BACKQUOTE:
                return KEY_TILDE;
            case SDLK_UP:
                return KEY_ARROW_UP;
            case SDLK_DOWN:
                return KEY_ARROW_DOWN;
            case SDLK_LEFT:
                return KEY_ARROW_LEFT;
            case SDLK_RIGHT:
                return KEY_ARROW_RIGHT;
        }

        return KEY_UNKNOWN;
    }
}