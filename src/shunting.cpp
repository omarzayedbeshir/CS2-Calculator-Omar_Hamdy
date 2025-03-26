#ifndef SHUNTING_CPP
#define SHUNTING_CPP
#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
#include <cstdlib>

#include "../include/shunting.h"

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
            else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
                     expr[i] == '/' || expr[i] == '^' || expr[i] == '(' ||
                     expr[i] == ')')
            {
                tokens.push_back(string(1, expr[i]));
                i++;
            }
            else if (isspace(expr[i]))
                i++;
            else
                cerr << "Invalid character ignored: " << expr[i] << endl;
        }

        for (int i = 0; i < tokens.size() - 1; i++)
        {
            if (
                (isdigit(tokens[i][0]) && tokens[i + 1] == "(") ||
                (tokens[i] == ")" && isdigit(tokens[i + 1][0]))
            )
                tokens.insert(tokens.begin() + i + 1, "*");
        }
        
        return tokens;
    }

int getPrecedence(const string& op)
{
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;

    return -1;
}

ParenthesisAssociativity getAssociativity(const string& op)
{
    if (op == "^") return RIGHT;
    return LEFT;
}

vector<string> infixToPostfix(const vector<string>& tokens)
{
    for (int i = 1; i < tokens.size(); i++)
    {
        if (isdigit(tokens[i - 1][0]) && tokens[i] == "(")
            throw invalid_argument("Missing operator between number and \'(\'.");
        if (tokens[i - 1] == ")" && isdigit(tokens[i][0]))
            throw invalid_argument("Missing operator between \')\' and number.");
    }

    vector<string> output;
    stack<string> opStack;

    for (const string& token : tokens)
    {
        if (isdigit(token[0]))
            output.push_back(token);
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
            {
                cerr << "Mismatched parentheses: extra \')\' found.\n";
                exit(1);
            }

            opStack.pop();
        }
        else
        {
            while (!opStack.empty() && opStack.top() != "(")
            {
                string topOp = opStack.top();
                int topPrec = getPrecedence(topOp);
                int currPrec = getPrecedence(token);
                if (topPrec > currPrec || 
                    (topPrec == currPrec && getAssociativity(token) == LEFT))
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

}

#endif
