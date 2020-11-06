project(smarthome-service-tests CXX)

add_executable(smarthome-service-mocks "")

message(STATUS "Adding service testing sources")
add_subdirectory("src")

message(STATUS "Handling testing dependencies")
include("extern/upstream/CMakeLists.txt")

message(STATUS "Linking testing targets")
target_link_libraries(
    smarthome-service-mocks
    PUBLIC
        smarthome-mock
        smarthome-service
        gtest gtest_main gmock
)

add_test(
    NAME smarthome-service-mocks
    COMMAND "$<TARGET_FILE:smarthome-service-mocks>"
)