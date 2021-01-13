/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    entity.cpp
 * @brief   An entity that can be used on stage. This can either be a visual 
 *          element or a logical one (eg, for an audio emitter).
 */

#include "entity.hpp"

namespace kabuki
{
    entity::entity(std::string tag) : engine_component(tag)
    {
        
    }

    void entity::tick()
    {
        // Calculate velocity
        _velocity = _position - _last_position;
        _last_position = _position;
        
        on_tick();
    }
}