#pragma once
#include "../include/calculator.h"
#include <iostream>
#include <random>
#include <ctime>
#include <stdexcept>

using namespace std;

srand(time(0));

double subtract(double x, double y) {
    return x - y;
}

double divide(double x, double y) {
    try {
        if (y == 0)
            throw runtime_error("Division by zero not allowed!");
        return x / y;
    } catch(const runtime_error& e) {
        cout << e.what() << endl;
    }
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
    try {
        if (end < start)
            throw runtime_error("End must be greater than start!");
        return rand() % (end - start + 1) + start;
    } catch(const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
    
}
