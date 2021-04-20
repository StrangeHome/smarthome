#pragma once

#include <memory>
#include <string>

namespace smarthome {

    /**
     * Pure abstract base application logger.
    */
    class Logger {
        public:

            /**
             * Log the specified debug message.
             *
             * @param msg Message to log.
             */
            virtual void debug(const std::string msg) const = 0;

            /**
             * Log the specified informational message.
             *
             * @param msg Message to log.
             */
            virtual void info(const std::string msg) const = 0;

            /**
             * Log the specified warning message.
             *
             * @param msg Message to log.
             */
            virtual void warn(const std::string msg) const = 0;

            /**
             * Log the specified error message.
             *
             * @param msg Message to log.
             */
            virtual void error(const std::string msg) const = 0;

            /**
             * Log the specified critical message.
             *
             * @param msg Message to log.
             */
            virtual void critical(const std::string msg) const = 0;
    };

} // namespace smarthome
