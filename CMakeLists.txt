cmake_minimum_required(VERSION 3.20)
project(test)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message(STATUS "Find ${CCACHE_PROGRAM}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
else()
  message(WARNING "Not found ${CCACHE_PROGRAM}, install with 'sudo apt install ccache'")
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(proto)

add_executable(main src/main.cc)
target_link_libraries(main
    PRIVATE
    pthread
    custom_proto
)

