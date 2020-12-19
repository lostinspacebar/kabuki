/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    event.hpp
 * @brief   Base event 
 */

#ifndef KABUKI_EVENT_H_
#define KABUKI_EVENT_H_

namespace kabuki::events
{
    enum event_type
    {
        INPUT_EVENT
    };

    struct event
    {
        event_type type;
    };

    enum input_event_type
    {
        KEYBOARD_EVENT,
        MOUSE_EVENT,
        GAMEPAD_EVENT
    };

    struct input_event : event
    {
        input_event_type input_type;
    };
}

#endif