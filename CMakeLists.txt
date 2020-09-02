cmake_minimum_required(VERSION 3.10)

# set the project name
project(my_test_project LANGUAGES CXX)

# enable testing support
enable_testing()

#Add sub directories
add_subdirectory (lib)
add_subdirectory (demo)
