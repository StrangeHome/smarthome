project(smarthome-logger-tests CXX)

add_executable(smarthome-logger-tests "")

message(STATUS "Adding logger testing sources")
add_subdirectory("src")

message(STATUS "Handling testing dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking testing targets")
target_link_libraries(
    smarthome-logger-tests
    PUBLIC
        smarthome-logger
        gtest gtest_main gmock
)

add_test(
    NAME smarthome-logger-tests
    COMMAND "$<TARGET_FILE:smarthome-logger-tests>"
)