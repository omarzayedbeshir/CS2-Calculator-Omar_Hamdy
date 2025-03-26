#pragma once
#include <iostream>
#include "../include/calculator.h"

double add(double x, double y) { return (x + y); }

double multiply(double x, double y) { return (x * y); }

int factorial(int x)
{
	if (x == 0 || x == 1)
		return 1;

	return x * factorial(x - 1);
}

int LCM(int x, int y)
{
	int greater = max(a, b);
	int smaller = min(a, b);
	for (int i = greater; ; i+= greater)
		if (i % smallest == 0)
			return i;
}
