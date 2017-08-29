cmake_minimum_required(VERSION 3.8)
project(Remote_Memory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp server.cpp Structures/linkedList.h Structures/linkedList.cpp Structures/node.cpp Structures/node.h)
add_executable(Remote_Memory ${SOURCE_FILES})