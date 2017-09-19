cmake_minimum_required(VERSION 3.8)
project(Remote_Memory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp server.cpp Structures/LinkedList.h Structures/LinkedList.cpp Structures/Node.cpp Structures/Node.h Servers/Server.cpp Servers/Server.h rmlib/rmlib.cpp rmlib/rmlib.h)
add_executable(Remote_Memory ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} pthread)