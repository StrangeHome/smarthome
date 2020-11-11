
# from install_dependencies import install_dependencies
# import subprocess

# def setup_developer_machine():

#     print("Installing development dependencies.")
#     install_dependencies(["clang", "ninja"])

#     cmake_version = "cmake-3.15.7"
#     cmake_file_name = cmake_version + ".tar.gz"
#     print("Fetching CMake 3.15.7 from cmake.org")
#     subprocess.run(["sudo", "wget", "https://cmake.org/files/v3.15/" + cmake_file_name])

#     print("Making dependency folder ../_dep")
#     subprocess.run(["mkdir", "-p", "../_dep"])

#     print("Moving cmake into _dep folder.")
#     subprocess.run(["mv", cmake_file_name, "../_dep/"])

#     subprocess.run(["cd", "../_dep"])

#     print("Extracting cmake contents")
#     subprocess.run(["tar", "-xzvf", cmake_file_name])

#     print("Bootstrapping cmake.")
#     subprocess.run(["cd", cmake_version])
#     subprocess.run(["./bootstrap"])

#     print("Making cmake.")
#     subprocess.run(["make"])

#     print("Configuring cmake.")
#     subprocess.run(["./configure"])

# if __name__ == "__main__":
#     setup_developer_machine()