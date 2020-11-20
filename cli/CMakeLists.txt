project(smarthome-distribution-cli CXX)

message(STATUS "Handling distribution CLI dependencies")
include("extern/upstream/CMakeLists.txt")

add_executable(smarthome-distribution-cli "${CMAKE_CURRENT_LIST_DIR}/cli.cpp")
set_target_properties(smarthome-distribution-cli PROPERTIES OUTPUT_NAME "smarthome")

message(STATUS "Linking distribution CLI target libraries")
target_link_libraries(smarthome-distribution-cli
    PRIVATE
        smarthome-client
        smarthome-logger
        cppject
        CLI11::CLI11)
