#include "../include/calculator.h"
#include <iostream>
#include <random>
#include <ctime>
#include <stdexcept>
using namespace std;

double subtract(double x, double y) { return (x - y); }

double add(double x, double y) { return (x + y); }

double multiply(double x, double y) { return (x * y); }

int factorial(int x)
{
    if (x < 0)
        throw invalid_argument("Factorial of negative number is undefined");

	if (x == 0 || x == 1)
		return 1;

	return x * factorial(x - 1);
}

int LCM(int x, int y)
{
    if (x == 0 || y == 0)
        throw invalid_argument("LCM of zero is undefined");

	int greater = max(x, y);
	int smaller = min(x, y);
	for (int i = greater; ; i+= greater)
		if (i % smaller == 0)
			return i;
}

double divide(double x, double y)
{
    if (y == 0)
        throw runtime_error("Division by zero not allowed!");

    return (x / y);

    return 0;
}

int GCD(int x, int y) {
    if (x == 0)
        return y;
    else if (y == 0)
        return x;
    else {
        int max_num = max(x, y);
        int min_num = min(x, y);
        max_num = max_num % min_num;
        return GCD(min_num, max_num);
    }
}

int random(int start, int end) {
    if (end < start)
        throw invalid_argument("Invalid range: End must be greater than start!");

	srand(static_cast<unsigned int>(time(NULL)));
	return rand() % (end - start + 1) + start;

    return 0;
}
