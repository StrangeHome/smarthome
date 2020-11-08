import subprocess

def install_dependencies():

    aptitude = subprocess.run(["which", "apt-get"])
    if (aptitude):
        subprocess.run(["sudo", "apt-get", "update"])
        subprocess.run(["sudo", "apt-get", "-y", "install", "bison", "flex", "graphviz", "doxygen"])
    else:
        subprocess.run(["sudo", "yum", "update"])
        subprocess.run(["sudo", "yum", "-y", "install", "bison", "flex", "graphviz", "doxygen"])


if __name__ == "__main__":
    install_dependencies()