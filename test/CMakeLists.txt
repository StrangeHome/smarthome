project(smarthome-distribution-tests CXX)

add_executable(smarthome-distribution-tests "")

# Handle testing dependencies
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking smarthome testing targets")
target_link_libraries(
    smarthome-distribution-tests 
    PUBLIC 
        smarthome
        gtest gtest_main gmock
)
message(STATUS "Linking smarthome testing targets - done")

add_test(
    NAME smarthome-distribution-tests
    COMMAND "$<TARGET_FILE:smarthome-distribution-tests>"
)  