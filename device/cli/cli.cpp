
#include <smarthome/logger/apply_production_logger.hpp>
#include <smarthome/logger/logger.hpp>
#include <cppject/service_factory.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into smarthome devices."};

    bool start = false;
    cli.add_flag("-s,--start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    auto serviceFactory = smarthome::ServiceFactory::Instance();
    auto logger = serviceFactory->Get<smarthome::Logger>();
    if (start)
        logger->info("Starting device...");

    return 0;
}