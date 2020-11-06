target_sources(smarthome-mock
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/all.cpp>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/all.cpp>")