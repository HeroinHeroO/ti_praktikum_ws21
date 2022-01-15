cmake_minimum_required(VERSION 3.21)
project(ti_praktikum_ws21 C)

set(CMAKE_C_STANDARD 17)

add_executable(ti_praktikum_ws21 main.c sorts.c sorts.h littlehelpers.c littlehelpers.h "main 1.1.c" "main 1.2.c" "main 1.3.c")
