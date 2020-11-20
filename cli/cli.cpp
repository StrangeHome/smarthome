
#include <smarthome/apply_production_client.hpp>
#include <smarthome/client.hpp>
#include <smarthome/logger.hpp>

#include <cppject/service_factory.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into the smarthome distribution."};
    auto serviceFactory = smarthome::ServiceFactory::Instance();
    auto logger = serviceFactory->Get<smarthome::Logger>();

    // TODO:
    auto client = serviceFactory->Get<smarthome::Client>();
    // cli.add_option("-c,--config", client, "Provide a configuration with which the system will be started.");

    // TODO:
    bool discoverDevices = false;
    cli.add_flag("-d,--discover", discoverDevices, "Run auto-discovery of peripheral devices.");

    CLI11_PARSE(cli, argc, argv);

    if (discoverDevices) {

        logger->info("Auto-discovering devices...");
        client->DiscoverDevices();
    }

    return 0;
}