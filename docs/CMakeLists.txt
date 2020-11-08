project(smarthome-docs CXX)

set(DOXYFILE_IN ${CMAKE_CURRENT_LIST_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

include("extern/upstream/CMakeLists.txt")

# configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

# add_custom_target(
#     doc_doxygen ALL
#     COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Generating API documentation with Doxygen"
#     VERBATIM )