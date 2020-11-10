import subprocess
import sys

def install_dependencies():

    package_manager = "apt-get"
    aptitude = subprocess.run(["which", "apt-get"])
    if (not aptitude):
        package_manager = "yum"

    dependencies = sys.argv[1:]

    print("Updating OS package manager.\n", sys.stdout)
    subprocess.run(["sudo", package_manager, "update"])

    print("Installing dependencies: " + str(dependencies) + "\n", sys.stdout)
    subprocess.run(["sudo", package_manager, "-y", "install", *dependencies])

if __name__ == "__main__":
    install_dependencies()