
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into arbitrary smart devices."};

    bool start = false;
    cli.add_option("start", start, "Start the device.");

    CLI11_PARSE(cli, argc, argv);

    return 0;
}