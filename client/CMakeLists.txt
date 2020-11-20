project(smarthome-client CXX)

add_library(smarthome-client INTERFACE)
add_library(smarthome::client ALIAS smarthome-client)

include("extern/upstream/CMakeLists.txt")

add_subdirectory("include")

target_link_libraries(smarthome-client INTERFACE smarthome-logger cppject)

message(STATUS "Linking smarthome library targets")
