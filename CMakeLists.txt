cmake_minimum_required(VERSION 3.10)
project(VectorscopeVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vectorscope
    src/main.cpp
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Threads REQUIRED)

# websocketpp and boost are optional; expected to be installed on system
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

 target_link_libraries(vectorscope PRIVATE
    glfw
    OpenGL::GL
    Threads::Threads
    ${Boost_LIBRARIES}
)

install(TARGETS vectorscope RUNTIME DESTINATION bin)
