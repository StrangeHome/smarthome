message(STATUS "Fetching logger library dependencies")

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog"
    GIT_TAG "v1.8.1"
    GIT_PROGRESS TRUE)

FetchContent_Declare(
    cppject
    GIT_REPOSITORY "https://github.com/haydenmcp/cppject"
    GIT_TAG "main"
    GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(cppject spdlog)