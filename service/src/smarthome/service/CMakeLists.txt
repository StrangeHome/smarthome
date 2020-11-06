target_sources(smarthome-service
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/service_factory.cpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/service_factory.cpp>")