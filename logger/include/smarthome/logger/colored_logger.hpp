#pragma once

#include <smarthome/logger/logger.hpp>

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace smarthome {

    namespace {

        /**
         * Configure the spdlog logger before object assignment.
         */
        const std::shared_ptr<spdlog::logger> configure_logger();

        const std::shared_ptr<spdlog::logger> configure_logger() {

            auto logger = spdlog::get("console");
            if (logger == nullptr) {
                // create color multi threaded logger
                logger = spdlog::stdout_color_mt("console");
                auto err_logger = spdlog::stderr_color_mt("stderr");
                spdlog::set_level(spdlog::level::debug);
                spdlog::get("console")->debug("Logger configured.");
            }
            return logger;
        }

    } // anonymous namespace

    /**
     * Colored console logger implementation.
     */
    class ColoredLogger : public Logger {
        public:

            ColoredLogger() : _logger( configure_logger() ) { }

            void debug(const std::string msg) {
                _logger->debug(msg);
            }

            void info(const std::string msg) {
                _logger->info(msg);
            }

            void warn(const std::string msg) {
                _logger->warn(msg);
            }

            void error(const std::string msg) {
                _logger->error(msg);
            }

            void critical(const std::string msg) {
                _logger->critical(msg);
            }

        private:
            const std::shared_ptr<spdlog::logger> _logger;
    };

} // namespace smarthome