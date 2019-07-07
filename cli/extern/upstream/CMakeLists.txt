include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

message(STATUS "Fetching smarthome CLI dependencies")
FetchContent_Declare(
    cli11
    GIT_REPOSITORY "https://github.com/CLIUtils/CLI11"
    GIT_TAG "v1.8.0"
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(cli11)