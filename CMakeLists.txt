
cmake_minimum_required(VERSION 3.12)

project(Sandbox LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SDL3 REQUIRED)

add_subdirectory(ext/glad)

add_executable(sandbox src/main.cpp)

target_link_libraries(sandbox PRIVATE SDL3::SDL3 glad)
