cmake_minimum_required(VERSION 4.0)
project(shader-opengl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(shader-opengl
    src/main.cpp
    include/eunoia/Window.cpp
    include/eunoia/Arch.cpp
    include/eunoia/Shader.cpp
    src/glad.c
)

target_include_directories(shader-opengl PRIVATE include)
target_link_libraries(shader-opengl PRIVATE glfw GL glm)
