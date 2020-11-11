
message(STATUS "Updating system dependencies to install.")
set(SMARTHOME_PACKAGE_DEPENDENCIES ${SMARTHOME_PACKAGE_DEPENDENCIES}
    "qt5-default" "qtdeclarative5-dev" "mesa-common-dev" "libglu1-mesa-dev" PARENT_SCOPE)