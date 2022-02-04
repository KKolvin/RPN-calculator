cmake_minimum_required(VERSION 3.18)
project(ps4 C)

set(CMAKE_C_STANDARD 99)

add_executable(ps4 main.c node.c node.h stack.c stack.h rpn.c rpn.h errors.h errors.c rpn-converter.c rpn-converter.h)
