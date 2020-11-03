 target_sources(
    smartdevice
     INTERFACE
         "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.hpp>"
 )
