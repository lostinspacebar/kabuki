/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    scene.hpp
 * @brief   Represents a single scene that can be shown on stage.
 */

#ifndef KABUKI_SCENE_H_
#define KABUKI_SCENE_H_

#include "engine_component.hpp"

namespace kabuki
{
    class scene : public engine_component
    {
    public:
        scene();
    };
}

#endif