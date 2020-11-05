
#include <smarthome/logger/logger.hpp>


#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace smarthome {

    namespace {

        /**
         * Configure the spdlog logger before object assignment.
         */
        const std::shared_ptr<spdlog::logger> configure_logger();

        const std::shared_ptr<spdlog::logger> configure_logger() {

            // create color multi threaded logger
            auto console = spdlog::stdout_color_mt("console");
            auto err_logger = spdlog::stderr_color_mt("stderr");
            spdlog::set_level(spdlog::level::debug);

            spdlog::get("console")->info("Logger configured.");

            return console;
        }

    } // anonymous namespace

        Logger::Logger() : _logger( configure_logger() ) { }

        void Logger::debug(const std::string msg) {
            _logger->debug(msg);
        }

        void Logger::info(const std::string msg) {
            _logger->info(msg);
        }

        void Logger::warn(const std::string msg) {
            _logger->warn(msg);
        }

        void Logger::error(const std::string msg) {
            _logger->error(msg);
        }

        void Logger::critical(const std::string msg) {
            _logger->critical(msg);
        }

} // namespace smarthome