target_sources(
    smarthome
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/smarthome.cpp>"
)