message(STATUS "Fetching device CLI dependencies")

FetchContent_Declare(
    cli11
    GIT_REPOSITORY "https://github.com/CLIUtils/CLI11"
    GIT_TAG "v1.8.0"
    GIT_PROGRESS TRUE)

FetchContent_Declare(
    cppject
    GIT_REPOSITORY "https://github.com/haydenmcp/cppject"
    GIT_TAG "main"
    GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(cli11 cppject)