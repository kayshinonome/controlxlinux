cmake_minimum_required(VERSION 3.13)
string(TIMESTAMP TODAY "%Y%m%d")
project("controlxlinux")
set(CMAKE_CXX_STANDARD 17)
include_directories("include")
file(GLOB source_files "src/*.cpp")
add_executable(controlxlinux ${source_files})
target_link_libraries(${PROJECT_NAME} stdc++fs)
add_compile_options(-Wall -Wextra -Werror -O2)
install(TARGETS controlxlinux RUNTIME DESTINATION bin)
