/**
 * KABUKI GAME ENGINE / log
 * ----------------------------------------------------------------------------
 * @file    log.hpp
 * @brief   Logging abstraction for in-engine usage. Recommended to use this 
 *          instead of a logging implementation directly.
 */

#ifndef KABUKI_LOG_H
#define KABUKI_LOG_H

#include "spdlog/spdlog.h"

namespace kabuki::utility 
{
    class log
    {
    public:
        log(const char *tag);
        template<typename... Args> void debug(const char *fmt, Args... args)
        {
            _log->debug(fmt, args...);
        }
        template<typename... Args> void info(const char *fmt, Args... args)
        {
            _log->info(fmt, args...);
        }
        template<typename... Args> void warn(const char *fmt, Args... args)
        {
            _log->warn(fmt, args...);
        }
        template<typename... Args> void error(const char *fmt, Args... args)
        {
            _log->error(fmt, args...);
        }
    private:
        std::shared_ptr<spdlog::logger> _log;
    };
}

#endif