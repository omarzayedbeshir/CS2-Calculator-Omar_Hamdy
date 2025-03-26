#ifndef SHUNTING_H
#define SHUNTING_H
#include <iostream>
#include <vector>
using namespace std;

enum ParenthesisAssociativity { LEFT, RIGHT };

namespace ShuntYard
{

    vector<string> tokenize(const string& expr);

    int getPrecedence(const string& op);

    ParenthesisAssociativity getAssociativity(const string& op);

    vector<string> infixToPostfix(const vector<string>& token);
}

#endif
