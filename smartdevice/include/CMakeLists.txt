message(STATUS "Handling smartdevice library headers...")

add_subdirectory("smartdevice")

target_include_directories(
    smartdevice
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
)