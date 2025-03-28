# CS2 Calculator Application

## Introduction
This is a calculator application for an assignment in the CS2 Lab course. The application allows users to perform multiple mathematical operations, including arithmetic calculations and advanced functions like factorial, GCD, and LCM computations.

## Features
### Available Operations
- Addition of two numbers
- Subtraction of two numbers
- Multiplication of two numbers
- Division of two numbers
- Factorial calculation
- Greatest Common Divisor (GCD) calculation
- Least Common Multiple (LCM) calculation
- Random number generation (within a range)
- Expression parsing and evaluation

## Build Instructions
To build the application, follow these steps:

### Prerequisites
Ensure you have the following installed on your system:
- CMake (minimum version 3.10)
- A C++ compiler supporting C++17

### Build Steps
1. Navigate to the project's directory:
   ```sh
   cd path/to/project/
   ```
2. Create a `build` directory and enter it:
   ```sh
   mkdir build && cd build
   ```
3. Run CMake to generate the build files:
   ```sh
   cmake ..
   ```
4. Compile the project using `make`:
   ```sh
   make
   ```
5. Run the calculator application:
   ```sh
   ./test
   ```
6. (OPTIONAL) Run the shunt test program to validate its functionality (or alternatively, you can use this functionality in the test application):
   ```sh
   ./shunt-test
   ```

    The test results will indicate whether all cases pass successfully or if any failures occur.

## File Structure
```
CalculatorProject/
├── CMakeLists.txt
├── include/
│   ├── calculator.h
│   ├── shunting.h
├── src/
│   ├── calculator.cpp
│   ├── shunting.cpp
├── tests/
│   ├── test.cpp
│   ├── shunt-test.cpp
├── build/ (generated after running CMake)
└── README.md
```

## Feedback
If you have any feedback or suggestions, please contact us:
- zayed.omar@aucegypt.edu
- hamdyousama79@gmail.com | hamdy_osama@aucegypt.edu