target_sources(smarthome-logger
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/colored_logger.cpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/colored_logger.cpp>")