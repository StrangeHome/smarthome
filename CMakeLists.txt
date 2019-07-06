cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(
    smarthome-distribution
    HOMEPAGE_URL "https://github.com/haydenmcp/smarthome"
    LANGUAGES CXX
)
include(GNUInstallDirs)

# TODO: Replace this standard designation with specific cxx feature registry.
# This will avoid breakage that results from upgrading c++ versions (frailty)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SMARTHOME_MASTER_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(SMARTHOME_MASTER_PROJECT ON)
endif()

option(SMARTHOME_INCLUDE_CLI "Include distribution command-line interface (CLI)" ${SMARTHOME_MASTER_PROJECT})
option(SMARTHOME_INCLUDE_SOURCES "Include distribution sources." ${SMARTHOME_MASTER_PROJECT})
option(SMARTHOME_INCLUDE_TESTS "Include distribution tests." ${SMARTHOME_MASTER_PROJECT})

if (SMARTHOME_INCLUDE_CLI)
    add_subdirectory("cli")
endif()

if (SMARTHOME_INCLUDE_SOURCES)
    add_subdirectory("smarthome")
endif()

if (SMARTHOME_INCLUDE_TESTS)
    enable_testing()
    add_subdirectory("test")
endif()