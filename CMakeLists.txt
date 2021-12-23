cmake_minimum_required(VERSION 3.19)
project(IO)

set(CMAKE_CXX_STANDARD 17)

add_executable(IO source/main.cpp source/FileReader.cpp include/FileReader.h include/DataFrame.h source/DataFrame.cpp)
