message(STATUS "Handling library headers...")

add_subdirectory("smarthome")

target_include_directories(
    smarthome-client
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
)