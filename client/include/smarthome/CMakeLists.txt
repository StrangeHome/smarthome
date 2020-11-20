 target_sources(
    smarthome-client
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/apply_production_client.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/client.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/client_impl.hpp>"

        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/apply_production_client.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/client.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/client_impl.hpp>"
 )
