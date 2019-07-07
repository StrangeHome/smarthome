cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(smarthome-distribution LANGUAGES CXX HOMEPAGE_URL "https://github.com/haydenmcp/smarthome")
include(GNUInstallDirs)
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

math(EXPR SMARTHOME_DISTRIBUTION_TARGET_ARCHITECTURE "8 * ${CMAKE_SIZEOF_VOID_P}")
set(FETCHCONTENT_BASE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/_dep/${CMAKE_GENERATOR}/${SMARTHOME_DISTRIBUTION_TARGET_ARCHITECTURE}"
    CACHE
    PATH
    ""
    FORCE)

# TODO: Replace this standard designation with specific cxx feature registry.
# This will avoid breakage that results from upgrading c++ versions (frailty)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(RELATIVE_PATH SMARTHOME_DISTRIBUTION_INSTALL_RELATIVE_RPATH
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_INSTALL_RPATH "${ORIGIN}" "${ORIGIN}/${SMARTHOME_DISTRIBUTION_INSTALL_RELATIVE_RPATH}")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage CACHE PATH "Default installation prefix." FORCE)
endif()

set(SMARTHOME_DISTRIBUTION_MASTER_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(SMARTHOME_DISTRIBUTION_MASTER_PROJECT ON)
endif()

option(SMARTHOME_INCLUDE_CLI "Include distribution command-line interface (CLI)" ${SMARTHOME_DISTRIBUTION_MASTER_PROJECT})
option(SMARTHOME_INCLUDE_SOURCES "Include distribution sources." ${SMARTHOME_DISTRIBUTION_MASTER_PROJECT})
option(SMARTHOME_INCLUDE_EXAMPLES "Include distribution sources." ${SMARTHOME_DISTRIBUTION_MASTER_PROJECT})
option(SMARTHOME_INCLUDE_TESTS "Include distribution tests." ${SMARTHOME_DISTRIBUTION_MASTER_PROJECT})

if(WIN32)
    message("\n")
    message(STATUS "Building for Win32")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if (SMARTHOME_INCLUDE_CLI)
    add_subdirectory("cli")
endif()

if (SMARTHOME_INCLUDE_SOURCES)
    add_subdirectory("smarthome")
endif()

if (SMARTHOME_INCLUDE_EXAMPLES)
    add_subdirectory("example")
endif()

if (SMARTHOME_INCLUDE_TESTS)
    enable_testing()
    add_subdirectory("test")
endif()