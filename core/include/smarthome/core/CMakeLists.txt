 target_sources(
     smarthome-core
     INTERFACE
         "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.hpp>"
 )
