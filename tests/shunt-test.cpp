#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../include/shunting.h"

using namespace std;

#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

struct TestResult
{
    int passed = 0;
    int failed = 0;
};

// Wrapper for test assertions based on macros
#define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            cerr << COLOR_RED << "F" << COLOR_RESET; \
            result.failed++; \
        } else { \
            cout << COLOR_GREEN << "." << COLOR_RESET; \
            result.passed++; \
        } \
    } while (0)


void testTokenize(TestResult& result) {
    vector<string> tokens;

    tokens = tokenize("3+4*2");
    TEST_ASSERT((tokens == vector<string>{"3", "+", "4", "*", "2"}), "Basic operators");

    tokens = tokenize("gcd(24,36)");
    TEST_ASSERT((tokens == vector<string>{"gcd", "(", "24", ",", "36", ")"}), "Function with args");

    tokens = tokenize("5(3+2)");
    TEST_ASSERT((tokens == vector<string>{"5", "*", "(", "3", "+", "2", ")"}), "Implicit multiplication");
}

void testInfixToPostfix(TestResult& result) {
    vector<string> postfix;

    postfix = infixToPostfix({"3", "+", "4", "*", "2"});
    TEST_ASSERT((postfix == vector<string>{"3", "4", "2", "*", "+"}), "Operator precedence");

    postfix = infixToPostfix({"gcd", "(", "24", ",", "36", ")"});
    TEST_ASSERT((postfix == vector<string>{"24", "36", "gcd"}), "Function call");

    postfix = infixToPostfix({"2", "^", "3", "^", "2"});
    TEST_ASSERT((postfix == vector<string>{"2", "3", "2", "^", "^"}), "Exponent associativity");
}

void testEvaluatePostFix(TestResult& result)
{
    double value;

    value = evaluatePostfix({"3", "4", "2", "*", "+"});
    TEST_ASSERT(fabs(value - 11.0) < 1e-6, "Basic arithmetic");

    value = evaluatePostfix({"24", "36", "gcd"});
    TEST_ASSERT(fabs(value - 12.0) < 1e-6, "GCD function");

    value = evaluatePostfix({"2", "3", "2", "*", "*"});
    TEST_ASSERT(fabs(value - 12.0) < 1e-6, "Repeated Operations");
}

int main()
{
    TestResult result;

    cout << "Running tests:\n";
    testTokenize(result);
    testInfixToPostfix(result);
    testEvaluatePostFix(result);

    cout << "\n\nResults:\n";
    cout << COLOR_GREEN << "Passed: " << result.passed << COLOR_RESET << "\n";
    cout << COLOR_RED << "Failed: " << result.failed << COLOR_RESET << "\n";

    return result.failed > 0 ? 1 : 0;
}
