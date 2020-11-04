
#include <smarthome/logger/logger.hpp>

#include <CLI/CLI.hpp>
#include <CLI/App.hpp>
#include <string>

int main(int argc, char** argv) {

    auto logger = smarthome::Logger();
    CLI::App cli{"Command-line Interface into arbitrary smart devices."};

    bool start = false;
    cli.add_option("start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    if (start)
        logger.info("Starting device...");

    return 0;
}