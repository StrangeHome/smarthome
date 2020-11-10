import subprocess

def install_dependencies():

    aptitude = subprocess.run(["which", "apt-get"])
    if (aptitude):
        subprocess.run(["sudo", "apt-get", "update"])
        subprocess.run(["sudo", "apt-get", "-y", "install", "qt5-default", "qtdeclarative5-dev"])
    else:
        subprocess.run(["sudo", "yum", "update"])
        subprocess.run(["sudo", "yum", "-y", "install", "qt5-default", "qtdeclarative5-dev"])


if __name__ == "__main__":
    install_dependencies()