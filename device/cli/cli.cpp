
#include <smarthome/logger/logger.hpp>
#include <smarthome/service/service_factory.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

// TODO List
//  1. Create automation scripts in Python (platform agnostic) to configure BeagelBone Black
//  for device run (i.e, ansible may be used to deploy to devices)
//  2. Implement dependency injection subsystem for mockability of software components. This
//  requires pure abstract bases. Implement in CPPJect project.
//  3. Incorporate doxygen documentation generation.

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into smarthome devices."};

    bool start = false;
    cli.add_flag("-s,--start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    auto service_factory = smarthome::ServiceFactory();
    // TODO
    // auto logger = service_factory.Get<Logger>();
    // if (start)
    //     logger.info("Starting device...");

    return 0;
}