project(smartdevice CXX)

add_library(smartdevice INTERFACE)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("include")

message(STATUS "Linking smartdevice library targets")
