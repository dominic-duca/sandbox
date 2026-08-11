
cmake_minimum_required(VERSION 3.12)

project(Sandbox LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SDL3 REQUIRED)

add_subdirectory(vendor/glad)

add_executable(sandbox
    src/Main.cpp
    src/ShaderProgram.cpp
    src/Shader.cpp
)

target_compile_definitions(sandbox PRIVATE SOURCE_DIR="${Sandbox_SOURCE_DIR}")

target_link_libraries(sandbox PRIVATE SDL3::SDL3 glad)
