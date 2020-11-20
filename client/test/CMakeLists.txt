project(smarthome-client-tests CXX)

add_executable(smarthome-client-tests "")

message(STATUS "Adding smarthome testing sources")
add_subdirectory("src")

message(STATUS "Handling smarthome testing dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking smarthome testing targets")
target_link_libraries(
    smarthome-client-tests
    PUBLIC
        smarthome-client
        gtest gtest_main gmock
)

add_test(
    NAME smarthome-client-tests
    COMMAND "$<TARGET_FILE:smarthome-client-tests>"
)