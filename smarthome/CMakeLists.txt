project(smarthome CXX)

add_library(smarthome STATIC "")
add_library(smarthome:: ALIAS smarthome)

# Handle Dependencies
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking smarthome targets")

message(STATUS "Linking smarthome targets - done")

