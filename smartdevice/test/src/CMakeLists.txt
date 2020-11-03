target_sources(
    smartdevice-tests
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/includes.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.cpp>"
)