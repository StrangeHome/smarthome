
#include <CLI/App.hpp>

int main(const int argc, char** argv) {

    CLI::App cli{"Command-line Interface into arbitrary smart devices."};

    CLI11_PARSE(cli, argc, argv);

    return 0;
}