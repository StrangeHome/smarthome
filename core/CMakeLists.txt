project(smarthome-core CXX)

add_library(smarthome-core STATIC "")
add_library(smarthome::core ALIAS smarthome-core)

include("extern/upstream/CMakeLists.txt")

message(STATUS "Handling smarthome library sources")
add_subdirectory("include")
add_subdirectory("src")

message(STATUS "Linking smarthome library targets")