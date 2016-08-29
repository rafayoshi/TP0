cmake_minimum_required(VERSION 3.6)
project(TP0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c arvore.c arvore.h)
add_executable(TP0 ${SOURCE_FILES})