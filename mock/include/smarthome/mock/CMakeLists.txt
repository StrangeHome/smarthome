target_sources(smarthome-mock
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/all.hpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/all.hpp>")