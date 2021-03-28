cmake_minimum_required(VERSION 3.13)

project("controlxlinux" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

file(GLOB source_files "src/*.cpp")

add_executable(controlxlinux ${source_files})

target_link_libraries(${PROJECT_NAME} stdc++fs)

add_compile_options(-Wall -Wextra ${platform_options})

install(TARGETS controlxlinux RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Tsuki Superior")
include(CPack)
