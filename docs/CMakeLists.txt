project(smarthome-docs CXX)

include("extern/upstream/CMakeLists.txt")

set(DOXYFILE_IN ${CMAKE_CURRENT_LIST_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

add_custom_target(
    smarthome-docs ALL
    COMMAND doxygen ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating smarthome distribution documentation."
    VERBATIM )