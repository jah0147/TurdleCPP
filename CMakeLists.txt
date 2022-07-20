cmake_minimum_required(VERSION 3.22)
project(TurdleCPP)


set(CMAKE_CXX_STANDARD 17)
#for Exe to work
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(TurdleCPP main.cpp console.cpp console.h delay.cpp delay.h wordGen.cpp wordGen.h game.cpp game.h keepScore.h sound.cpp sound.h)

# Link to GLFW, GLEW and OpenGL (sounds)
target_link_libraries(TurdleCPP PUBLIC
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        winMM.Lib)