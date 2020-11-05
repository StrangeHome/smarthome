
#include <smarthome/logger/logger.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

// TODO List
//  1. Create automation scripts in Python (platform agnostic) to configure BeagelBone Black
//  for device run (i.e, ansible may be used to deploy to devices)
//  2. Implement dependency injection subsystem for mockability of software components. This
//  requires pure abstract bases.

int main(int argc, char** argv) {

    auto logger = smarthome::Logger();
    CLI::App cli{"Command-line Interface into smarthome devices."};

    bool start = false;
    cli.add_flag("-s,--start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    if (start)
        logger.info("Starting device...");

    return 0;
}