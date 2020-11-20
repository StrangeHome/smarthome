
#include <smarthome/client.hpp>
#include <smarthome/apply_production_client.hpp>

#include <smarthome/logger.hpp>
#include <smarthome/apply_production_logger.hpp>

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
    bool discoverDevices = false;
    cli.add_flag("-d,--discover", discoverDevices, "Run auto-discovery of peripheral devices.");

    CLI11_PARSE(cli, argc, argv);

    auto serviceFactory = smarthome::ServiceFactory::Instance();
    auto client = serviceFactory->Get<smarthome::Client>();
    auto logger = serviceFactory->Get<smarthome::Logger>();

    if (discoverDevices) {

        logger->info("Auto-discovering devices...");
        client->DiscoverDevices();
    }

    return 0;
}