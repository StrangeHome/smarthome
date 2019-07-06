include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_BASE_DIR "${SMARTHOME_DEPENDENCY_DIR}" CACHE PATH "" FORCE)

message(STATUS "Fetching smarthome testing dependencies")

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "release-1.8.1"
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

message(STATUS "Fetching smarthome testing dependencies - done")