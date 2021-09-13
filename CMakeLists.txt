cmake_minimum_required(VERSION 3.20)
project(ccc C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(./cases S_CASES)

add_executable(ccc main.c  ${S_CASES})
