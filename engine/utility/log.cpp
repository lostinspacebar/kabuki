/**
 * KABUKI GAME ENGINE / log
 * ----------------------------------------------------------------------------
 * @file    log.cpp
 * @brief   Logging abstraction for in-engine usage. Recommended to use this 
 *          instead of a logging implementation directly.
 */

#include "log.hpp"

namespace kabuki::utility
{
    log::log(const char *tag)
    {
        _log = spdlog::default_logger()->clone(tag);
    }
}