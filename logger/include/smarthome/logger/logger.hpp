
#include <memory>
#include <string>
#include <spdlog/spdlog.h>

namespace smarthome {

    /**
     * Pure abstract base application logger.
    */
    class Logger {
        public:
            Logger();

            /**
             * Log the specified debug message.
             *
             * @param msg Message to log.
             */
            void debug(const std::string msg);

            /**
             * Log the specified informational message.
             *
             * @param msg Message to log.
             */
            void info(const std::string msg);

            /**
             * Log the specified warning message.
             *
             * @param msg Message to log.
             */
            void warn(const std::string msg);

            /**
             * Log the specified error message.
             *
             * @param msg Message to log.
             */
            void error(const std::string msg);

            /**
             * Log the specified critical message.
             *
             * @param msg Message to log.
             */
            void critical(const std::string msg);

        private:
            const std::shared_ptr<spdlog::logger> _logger;
    };

} // namespace smarthome
