import subprocess
import sys

def get_package_manager():

    package_manager = "apt-get"
    try:
        # If terminal locates package manager apt-get, continue
        subprocess.run(["which", "apt-get"]).check_returncode()
    except:
        package_manager = "yum"

    return package_manager

def get_dependencies_from_commandline():
    return sys.argv[1:]

def update_package_list(package_manager):
    print("Running: sudo " + package_manager + " update")
    subprocess.run(["sudo", package_manager, "update"])

def install_dependencies(package_manager, dependencies):
    print("Running: sudo " + package_manager + " -y install " + str(dependencies))
    subprocess.run(["sudo", package_manager, "-y", "install", *dependencies])

if __name__ == "__main__":

    package_manager = get_package_manager()
    dependencies = get_dependencies_from_commandline()
    update_package_list(package_manager)
    install_dependencies(package_manager, dependencies)