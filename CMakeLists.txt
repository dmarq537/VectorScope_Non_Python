cmake_minimum_required(VERSION 3.10)
project(OpenGLWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opengl_window
    src/main.cpp
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(opengl_window PRIVATE
    glfw
    OpenGL::GL
)

install(TARGETS opengl_window RUNTIME DESTINATION bin)
