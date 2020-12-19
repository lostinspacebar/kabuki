/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    stage.hpp
 * @brief   Represents the stage that contains all game components.
 */

#include "input_manager.hpp"

namespace kabuki
{
    class stage
    {
    public:
        stage(std::shared_ptr<input_manager> input);
    };
}