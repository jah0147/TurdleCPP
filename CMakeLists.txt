cmake_minimum_required(VERSION 3.22)
project(TurdleCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(TurdleCPP main.cpp console.cpp console.h delay.cpp delay.h wordGen.cpp wordGen.h game.cpp game.h keepScore.h)
