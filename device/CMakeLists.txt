project(smarthome-device CXX)

add_library(smarthome-device STATIC "")
add_library(smarthome::device ALIAS smarthome-device)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("cli")

add_subdirectory("include")

if(INCLUDE_SMARTHOME_TESTS)
    add_subdirectory("test")
endif()

message(STATUS "Linking device library targets")
target_link_libraries(smarthome-device PUBLIC smarthome-logger)
