cmake_minimum_required(VERSION 4.0)
project(testShader)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(testShader
    src/main.cpp
    include/eunoia/Window.cpp
    include/eunoia/Arch.cpp
    include/eunoia/Shader.cpp
    src/glad.c
)

target_include_directories(testShader PRIVATE include)
target_link_libraries(testShader PRIVATE glfw GL glm)
