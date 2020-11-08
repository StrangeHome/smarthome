message(STATUS "Fetching library dependencies")

execute_process(
    COMMAND "sudo" "python3" "install_dependencies.py"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})