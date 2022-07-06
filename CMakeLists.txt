cmake_minimum_required(VERSION 3.22)
project(TurdleCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TurdleCPP main.cpp console.cpp console.h delay.cpp delay.h)
