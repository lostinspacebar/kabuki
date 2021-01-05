#include <iostream>
#include "kabuki.hpp"
#include <AL/al.h>
#include <AL/alc.h>

static void list_audio_devices(const ALCchar *devices)
{
    const ALCchar *device = devices, *next = devices + 1;
    size_t len = 0;

    fprintf(stdout, "Devices list:\n");
    fprintf(stdout, "----------\n");
    while (device && *device != '\0' && next && *next != '\0') {
            fprintf(stdout, "%s\n", device);
            len = strlen(device);
            device += (len + 1);
            next += (len + 2);
    }
    fprintf(stdout, "----------\n");
}


int main(int argc, char * argv[])
{
    ALCdevice *device;

    device = alcOpenDevice(NULL);
    if (!device)
    {
        printf("Couldn't open device\n");
    }
    else
    {
        printf("Opened device\n");
    }

    ALboolean enumeration;

    enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
    if (enumeration == AL_FALSE)
    {
        printf("Cannot enumerate!\n");
        return -1;
    }
    else
    {
        printf("Can enumerate\n");
    }

    list_audio_devices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));

    kabuki::engine& engine = kabuki::engine::initialize("KABUKI 0.1", 1280, 720, 0);
    while(engine.is_running())
    {
        engine.tick();
    }
    return 0;
}