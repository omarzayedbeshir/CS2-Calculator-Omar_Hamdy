cmake_minimum_version(VERSION 3.10)

project(calculator)

set(SOURCE_FILES
    src/calculator.cpp
    test/test.cpp
)

add_executable(calculator ${SOURCE_FILES})
