add_subdirectory("smarthome/core")

target_include_directories(
    smarthome-core
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
)