project(smarthome-device CXX)

add_library(smarthome-device INTERFACE)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("cli")

add_subdirectory("include")

if(INCLUDE_SMARTHOME_TESTS)
    add_subdirectory("test")
endif()

message(STATUS "Linking smarthome device library targets")
