project(smarthome-device-cli CXX)

message(STATUS "Handling smarthome device CLI dependencies")
include("extern/upstream/CMakeLists.txt")

add_executable(smarthome-device-cli "${CMAKE_CURRENT_LIST_DIR}/cli.cpp")
set_target_properties(smarthome-device-cli PROPERTIES OUTPUT_NAME "smartdevice")

message(STATUS "Linking device CLI target libraries")
target_link_libraries(smarthome-device-cli
    PRIVATE
        smarthome-logger
        smarthome-service
        CLI11::CLI11)
