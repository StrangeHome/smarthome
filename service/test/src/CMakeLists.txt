target_sources(
    smarthome-service-mocks
    PRIVATE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/main.cpp>"
)