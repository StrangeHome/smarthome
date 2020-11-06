add_library(smarthome-service STATIC "")
add_library(smarthome::service ALIAS smarthome-service)

add_subdirectory("include")
add_subdirectory("src/smarthome/service")

if (INCLUDE_SMARTHOME_TESTS)
    add_subdirectory("test")
endif()