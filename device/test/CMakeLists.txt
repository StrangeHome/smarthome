project(smarthome-device-tests CXX)

add_executable(smarthome-device-tests "")

message(STATUS "Adding smarthome device testing sources")
add_subdirectory("src")

message(STATUS "Handling testing dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking testing targets")
target_link_libraries(
    smarthome-device-tests
    PUBLIC
        smarthome-device
        gtest gtest_main gmock
)

add_test(
    NAME smarthome-device-tests
    COMMAND "$<TARGET_FILE:smarthome-device-tests>"
)