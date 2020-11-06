target_sources(smarthome-service
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/service_factory.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/service_factory.hpp>")