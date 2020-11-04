 target_sources(
    smarthome-logger
     INTERFACE
         "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/logger.hpp>"
         "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/logger.hpp>"
 )
