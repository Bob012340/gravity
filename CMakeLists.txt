cmake_minimum_required(VERSION 3.12)
project(gravity)

set(CMAKE_CXX_STANDARD 17)

add_executable(gravity main.cpp particle.h particle.cpp)