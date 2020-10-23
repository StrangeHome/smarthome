project(smarthome-core CXX)

add_library(smarthome-core INTERFACE)
add_library(smarthome::core ALIAS smarthome-core)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("include")

message(STATUS "Linking smarthome library targets")
