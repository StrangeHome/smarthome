project(smarthome-cli CXX)

message(STATUS "Handling smarthome CLI dependencies")
include("extern/upstream/CMakeLists.txt")

add_executable(smarthome-cli "${CMAKE_CURRENT_LIST_DIR}/cli.cpp")
set_target_properties(smarthome-cli PROPERTIES OUTPUT_NAME "smarthome")

message(STATUS "Linking smarthome CLI target libraries")
target_link_libraries(smarthome-cli PRIVATE CLI11::CLI11)

