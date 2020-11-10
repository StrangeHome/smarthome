import subprocess
import sys

def install_dependencies():

    package_manager = "apt-get"
    try:
        subprocess.run(["which", "apt-get"]).check_returncode()
    except:
        package_manager = "yum"

    dependencies = sys.argv[1:]

    print("Running: sudo " + package_manager + " update")
    subprocess.run(["sudo", package_manager, "update"])

    print("Running: sudo " + package_manager + " -y install " + str(dependencies))
    subprocess.run(["sudo", package_manager, "-y", "install", *dependencies])

if __name__ == "__main__":
    install_dependencies()