target_sources(smarthome-logger
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/apply_production_logger.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/colored_logger.hpp>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/logger.hpp>"

        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/apply_production_logger.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/colored_logger.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/logger.hpp>"
)
