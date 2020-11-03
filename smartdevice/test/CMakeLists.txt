project(smartdevice-tests CXX)

add_executable(smartdevice-tests "")

message(STATUS "Adding smartdevice testing sources")
add_subdirectory("src")

message(STATUS "Handling smartdevice testing dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking smartdevice testing targets")
target_link_libraries(
    smartdevice-tests
    PUBLIC
        smartdevice
        gtest gtest_main gmock
)

add_test(
    NAME smartdevice-tests
    COMMAND "$<TARGET_FILE:smartdevice-tests>"
)