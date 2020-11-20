message(STATUS "Fetching smarthome library dependencies")

FetchContent_Declare(
    cppject
    GIT_REPOSITORY "https://github.com/haydenmcp/cppject"
    GIT_TAG "main"
    GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(cppject)