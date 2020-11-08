import subprocess

def install_dependencies():
    success = False
    aptitude = subprocess.run(["which", "apt-get"])
    if (aptitude):
        subprocess.run(["sudo", "apt-get", "update"])
        success = subprocess.run(["sudo", "apt-get", "-y", "install", "bison", "flex", "doxygen"])
    else:
        subprocess.run(["sudo", "yum", "update"])
        success = subprocess.run(["sudo", "yum", "-y", "install", "bison", "flex", "doxygen"])

    return success


if __name__ == "__main__":
    install_dependencies()