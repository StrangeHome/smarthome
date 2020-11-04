message(STATUS "Handling smarthome device library headers...")

add_subdirectory("smarthome/device")

target_include_directories(
    smarthome-device
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
)