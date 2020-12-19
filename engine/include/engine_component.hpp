/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    engine_component.hpp
 * @brief   Base component class that everything in kabuki inherits from.
 */

#ifndef KABUKI_ENGINE_COMPONENT_H_
#define KABUKI_ENGINE_COMPONENT_H_

#include "utility/log.hpp"

namespace kabuki
{
    class engine_component
    {
    public:
        engine_component(const char *tag)
        {
            _log = utility::log::create(tag);
        }
        virtual ~engine_component() {}
    protected:
        std::shared_ptr<utility::log> _log;
    };
}

#endif