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
    std::unique_ptr<log> log::create(const char *tag)
    {
        return std::unique_ptr<log>(new log(tag));
    }

    log::log(const char *tag)
    {
        spdlog::default_logger()->set_level(spdlog::level::info);
        _impl_log = spdlog::default_logger()->clone(tag);
    }
}