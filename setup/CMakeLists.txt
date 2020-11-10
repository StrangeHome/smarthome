execute_process(
    COMMAND "sudo" "python3" "install_dependencies.py" ${SMARTHOME_PACKAGE_DEPENDENCIES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})