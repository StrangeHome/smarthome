project(smarthome-service CXX)

add_library(smarthome-service INTERFACE)
add_library(smarthome::service ALIAS smarthome-service)

add_subdirectory("include")

if (INCLUDE_SMARTHOME_TESTS)
    add_subdirectory("test")
endif()