 target_sources(
    smarthome-client
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.hpp>"
 )
