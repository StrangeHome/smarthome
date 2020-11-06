add_subdirectory("smarthome/service")

target_include_directories(smarthome-service
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")