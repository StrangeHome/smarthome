project(smarthome-logger CXX)

add_library(smarthome-logger INTERFACE)
add_library(smarthome::logger ALIAS smarthome-logger)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("include")

message(STATUS "Linking logger library targets")
target_link_libraries(smarthome-logger
    INTERFACE
    smarthome-service
    spdlog::spdlog)

if(INCLUDE_SMARTHOME_TESTS)
    add_subdirectory("test")
endif()