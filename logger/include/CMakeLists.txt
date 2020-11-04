message(STATUS "Handling logger library headers...")

add_subdirectory("smarthome/logger")

target_include_directories(
    smarthome-logger
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
)