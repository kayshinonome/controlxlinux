cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project("controlxlinux" VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

file(GLOB source_files "src/*")

add_executable(controlxlinux ${source_files})

target_link_libraries(${PROJECT_NAME} stdc++fs)
