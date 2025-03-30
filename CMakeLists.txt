cmake_minimum_required(VERSION 3.10)
project(CalculatorProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)
add_executable(shunt-test tests/shunt-test.cpp src/calculator.cpp src/shunting.cpp)
add_executable(test tests/test.cpp src/calculator.cpp src/shunting.cpp)
