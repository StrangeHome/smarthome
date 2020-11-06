project(smarthome-mock CXX)

add_library(smarthome-mock STATIC "")
add_library(smarthome::mock ALIAS smarthome-mock)

add_subdirectory("include")
add_subdirectory("src/smarthome/mock")