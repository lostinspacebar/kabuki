#include <iostream>
#include "engine/kabuki.hpp"

int main(char **argv, int argc)
{
    kabuki::engine engine;
    kabuki::window *window = engine.create_window("KABUKI 0.1", 1280, 720);

    while(window->is_close_pending() == false)
    {
        window->present();
        engine.think();
    }
}