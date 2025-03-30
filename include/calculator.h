#pragma once

double add(double x, double y);
// Precondition: numeric inputs
// Purpose: adding two numbers x, and y, returning their sum (x + y).

double subtract(double x, double y);
// Precondition: numeric inputs
// Purpose: subtracting y from x, returning their subtracting (x - y).

double multiply(double x, double y);
// Precondition: numeric inputs
// Purpose: multiply two numerals (x * y)

double divide(double x, double y);
// Precondition: numeric inputs
// Purpose: divide two numerals (x / y)
// Postcondition: if y == 0, throws an exception

int factorial(int x);
// Precondition: numeric integer input
// Purpose: return the factorial of a number (x!)
// Postcondition: In case x < 0, throws an exception

int GCD(int x, int y);
// Precondition: numeric integer inputs
// Purpose: returns greatest common divisor
// Postcondition: In case x < 0 or y < 0, throws an exception

int LCM(int x, int y);
// Precondition: numeric integer inputs
// Purpose: returns lowest common multiple
// Postcondition: In case x < 0 or y < 0, throws an exception

int random(int start, int end);
// Precondition: numeric integer inputs
// Purpose: returns a random generated integer numeral
