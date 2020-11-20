
#include <smarthome/apply_production_logger.hpp>
#include <smarthome/logger.hpp>
#include <cppject/service_factory.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

using namespace cppject;

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into smarthome devices."};

    bool start = false;
    cli.add_flag("-s,--start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    auto serviceFactory = ServiceFactory::Instance();
    auto logger = serviceFactory->Get<smarthome::Logger>();
    if (start)
        logger->info("Starting device...");

    return 0;
}