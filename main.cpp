#include <iostream>
#include "kabuki.hpp"

int main(int argc, char * argv[])
{
    kabuki::engine& engine = kabuki::engine::initialize("KABUKI 0.1", 1280, 720, 0);
    while(engine.is_running())
    {
        engine.tick();
    }
    return 0;
}