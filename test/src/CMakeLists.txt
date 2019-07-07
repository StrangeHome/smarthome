target_sources(
    smarthome-distribution-tests
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/includes.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.cpp>"        
)