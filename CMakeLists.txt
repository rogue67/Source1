# set minimum cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# project name and language
project(resa LANGUAGES CXX)

# generate a library from sources
add_library(resekostnad
  STATIC
    resekostnad.h
    resekostnad.cpp
  )

add_executable(testNClass testNClass.cpp)

target_link_libraries(testNClass resekostnad)