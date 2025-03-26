#ifndef SHUNTING_CPP
#define SHUNTING_CPP
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <cstdlib>

#include "../include/shunting.h"
#include "../include/calculator.h"

using namespace std;

namespace ShuntYard
{
    // As adapted rom:
    // https://github.com/ozgekaracam/Shunting-Yard/blob/main/shunting_yard.cpp

    vector<string> tokenize(const string& expr)
    {
        vector<string> tokens;
        int i = 0;

        while ( i < expr.length())
        {
            if (isdigit(expr[i]))
            {
                string num;
                while (i < expr.length() && isdigit(expr[i]))
                {
                    num += expr[i];
                    i++;
                }

                tokens.push_back(num);
            }
            else if (isalpha(expr[i]))
            {
                string func;
                while (i <  expr.length() && isalpha(expr[i]))
                {
                    func += expr[i];
                    i++;
                }

                tokens.push_back(func);
            }
            else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
                     expr[i] == '/' || expr[i] == '(' ||
                     expr[i] == ')')
            {
                tokens.push_back(string(1, expr[i]));
                i++;
            }
            else if (expr[i] == ',')
            {
                tokens.push_back(",");
                i++;
            }
            else if (isspace(expr[i]))
                i++;
            else
            {
                cerr << "Invalid character ignored: " << expr[i] << endl;
                i++;
            }
        }

        for (int i = 0; i < tokens.size() - 1 ; i++)
        {
            bool leftCondition = (isdigit(tokens[i][0]) || tokens[i] == ")");
            bool rightCondition = (
                tokens[i + 1] == "(" ||
                isdigit(tokens[i + 1][0]) ||
                isalpha(tokens[i + 1][0])
            );

            if (leftCondition && rightCondition)
            {
                tokens.insert(tokens.begin() + i + 1, "*");
                i++;
            }
        }

        return tokens;
    }

    int getPrecedence(const string& op)
    {
        if (isalpha(op[0])) return 5;  // Not 4 in case we implemented power

        if (op == "*" || op == "/") return 3;
        if (op == "+" || op == "-") return 2;
        if (op == ",") return 1;

        return -1;
    }

    ParenthesisAssociativity getAssociativity(const string& op)
    {
        if (op == "^" || isalpha(op[0])) return RIGHT;
        return LEFT;
    }

    vector<string> infixToPostfix(const vector<string>& tokens)
    {
        vector<string> output;
        stack<string> opStack;

        for (const string& token : tokens)
        {
            if (isdigit(token[0]))
                output.push_back(token);
            else if (isalpha(token[0]))
                opStack.push(token);
            else if (token == ",")
            {
                while (!opStack.empty() && opStack.top() != "(")
                {
                    output.push_back(opStack.top());
                    opStack.pop();
                }

                if (opStack.empty())
                    throw invalid_argument("Mismatched comma.");
            }
            else if (token == "(")
                opStack.push(token);
            else if (token == ")")
            {
                while (!opStack.empty() && opStack.top() != "(")
                {
                    output.push_back(opStack.top());
                    opStack.pop();
                }

                if (opStack.empty())
                    throw invalid_argument("Mismatched parentheses.");
                
                opStack.pop();

                if (!opStack.empty() && isalpha(opStack.top()[0]))
                {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
            }
            else
            {
                while (!opStack.empty() && opStack.top() != "(")
                {
                    string topOp = opStack.top();
                    int currPrec = getPrecedence(token);
                    int topPrec = getPrecedence(topOp);

                    if (
                        (topPrec > currPrec) ||
                        (topPrec == currPrec && getAssociativity(token) == LEFT)
                    )
                    {
                        output.push_back(topOp);
                        opStack.pop();
                    }
                    else
                        break;
                }

                opStack.push(token);
            }
        }

        while (!opStack.empty())
        {
            if (opStack.empty())
            {
                cerr << "Mismatched parentheses: extra \'(\' found.\n";
                exit(1);
            }

            output.push_back(opStack.top());
            opStack.pop();
        }

        return output;
    }

    double evaluatePostfix(const vector<string>& postfix)
    {
        stack<double> operands;

        for (const string& token : postfix)
        {
            if (isdigit(token[0]))
                operands.push(stod(token));
            else if (isalpha(token[0]))
            {
                if (token == "factorial")
                {
                    if (operands.empty())
                        throw invalid_argument("Missing operand for factorial.");
                    
                    int x = static_cast<int>(operands.top());
                    operands.pop();
                    operands.push(factorial(x));
                }
                else if (token == "gcd")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for GCD.");
                    int b = static_cast<int>(operands.top());
                    operands.pop();

                    int a = static_cast<int>(operands.top());
                    operands.pop();
                    operands.push(GCD(a, b));
                }
                else if (token == "lcm")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for LCM.");
                    int b = static_cast<int>(operands.top());
                    operands.pop();

                    int a = static_cast<int>(operands.top());
                    operands.pop();

                    operands.push(LCM(a, b));
                }
                else if (token == "random")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for random.");
                    
                    int end = static_cast<int>(operands.top()); operands.pop();
                    int start = static_cast<int>(operands.top()); operands.pop();
                    if (start > end)
                        throw invalid_argument("Invalid range for random.");

                    operands.push(random(start, end));
                }
                else
                    throw invalid_argument("Unknown function: " + token);
            }
            else
            {
                if (token == "+")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for addition.");
                    
                    int b = static_cast<double>(operands.top()); operands.pop();
                    int a = static_cast<double>(operands.top()); operands.pop();

                    operands.push(add(a, b));
                }
                else if (token == "-")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for subtraction.");
                    
                    int b = static_cast<double>(operands.top()); operands.pop();
                    int a = static_cast<double>(operands.top()); operands.pop();

                    operands.push(subtract(a, b));
                }
                else if (token == "*")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for multiplication");
                    
                    int b = static_cast<double>(operands.top()); operands.pop();
                    int a = static_cast<double>(operands.top()); operands.pop();

                    operands.push(multiply(a, b));
                }
                else if (token == "/")
                {
                    if (operands.size() < 2)
                        throw invalid_argument("No enough operands for division");

                    int b = static_cast<double>(operands.top()); operands.pop();
                    int a = static_cast<double>(operands.top()); operands.pop();

                    operands.push(divide(a, b));
                }
            }
        }

        return operands.top();
    }
}

#endif
