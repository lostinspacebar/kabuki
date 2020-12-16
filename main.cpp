#include <iostream>
#include "engine/kabuki.hpp"

int main(char **argv, int argc)
{
    kabuki::utility::log log("Main");
    log.error("This is a test.");
}