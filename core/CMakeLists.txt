project(smarthome CXX)

add_library(smarthome STATIC "")
add_library(smarthome:: ALIAS smarthome)

message(STATUS "Handling smarthome library dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Handling smarthome library sources")
add_subdirectory("include")
add_subdirectory("src")

message(STATUS "Linking smarthome library targets")