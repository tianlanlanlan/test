cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main src/main.cc)

target_link_libraries(main
PRIVATE
pthread
)

