project(smartdevice-cli CXX)

message(STATUS "Handling smarthome device CLI dependencies")
include("extern/upstream/CMakeLists.txt")

add_executable(smartdevice-cli "${CMAKE_CURRENT_LIST_DIR}/cli.cpp")
set_target_properties(smartdevice-cli PROPERTIES OUTPUT_NAME "smartdevice")

message(STATUS "Linking device CLI target libraries")
target_link_libraries(smartdevice-cli PRIVATE CLI11::CLI11)
