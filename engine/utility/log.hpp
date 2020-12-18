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
    class log;

    class log
    {
    public:
        /**
         * Creates a Log instance with the specified tag. 
         * 
         * @param   tag Tag to added to every log message from this Log.
         */
        static std::shared_ptr<log> create(const char *tag);
        
        /**
         * Writes to the log with the DEBUG log level.
         */
        template<typename... Args> void debug(const char *fmt, Args... args)
        {
            _impl_log->debug(fmt, args...);
        }

        /**
         * Writes to the log with the INFO log level.
         */
        template<typename... Args> void info(const char *fmt, Args... args)
        {
            _impl_log->info(fmt, args...);
        }

        /**
         * Writes to the log with the WARNING log level.
         */
        template<typename... Args> void warn(const char *fmt, Args... args)
        {
            _impl_log->warn(fmt, args...);
        }

        /**
         * Writes to the log with the ERROR log level.
         */
        template<typename... Args> void error(const char *fmt, Args... args)
        {
            _impl_log->error(fmt, args...);
        }
    private:
        /**
         * Private constructor
         */
        log(const char *tag);

        // Implementation specific log instance
        std::shared_ptr<spdlog::logger> _impl_log;
    };
}

#endif