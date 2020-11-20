
#include <smarthome/logger/apply_production_logger.hpp>
#include <smarthome/logger/logger.hpp>
#include <cppject/service_factory.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into the smarthome distribution."};

    // TODO:
    // smarthome::Config config = smarthome::Config();
    // cli.add_option("-c,--config", config, "Provide a configuration with which the system will be started.");

    // TODO:
    bool autoDiscover = false;
    cli.add_flag("-a,--auto-discover", autoDiscover, "Run auto-discovery of peripheral devices.");

    CLI11_PARSE(cli, argc, argv);

    auto serviceFactory = smarthome::ServiceFactory::Instance();
    auto logger = serviceFactory->Get<smarthome::Logger>();
    if (autoDiscover)
        logger->info("Auto-discovering devices...");

    return 0;
}