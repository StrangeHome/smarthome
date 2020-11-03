message(STATUS "Fetching device CLI dependencies")
FetchContent_Declare(
    cli11
    GIT_REPOSITORY "https://github.com/CLIUtils/CLI11"
    GIT_TAG "v1.8.0"
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(CLI11)