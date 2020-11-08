message(STATUS "Fetching logger library dependencies")

message(STATUS "Downloading and installing doxygen dependencies")
execute_process(
    COMMAND "sudo" "python3" "install_dependencies.py"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})