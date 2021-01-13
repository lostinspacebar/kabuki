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
        engine_component(std::string tag)
        {
            _log = utility::log::create(tag);
        }

        inline utility::log *log() { return _log.get(); }

        virtual ~engine_component() {}
    private:
        std::unique_ptr<utility::log> _log;
    };
}

#endif