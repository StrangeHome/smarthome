
message(STATUS "Updating system dependencies to install.")
set(SMARTHOME_PACKAGE_DEPENDENCIES ${SMARTHOME_PACKAGE_DEPENDENCIES} "bison" "flex" "graphviz" "doxygen" PARENT_SCOPE)