
#include <CLI/CLI.hpp>
#include <CLI/App.hpp>

int main(int argc, char** argv) {

    CLI::App cli{"Command-line Interface into arbitrary smart devices."};


    bool test = false;
    cli.add_flag("-t", test, "A test flag.");

    CLI11_PARSE(cli, argc, argv);

    std::cout << "Flag: " << std::to_string(test);

    return 0;
}