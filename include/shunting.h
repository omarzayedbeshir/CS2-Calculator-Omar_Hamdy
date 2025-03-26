#ifndef SHUNTING_H
#define SHUNTING_H
#include <iostream>
#include <vector>
using namespace std;

enum ParenthesisAssociativity { LEFT, RIGHT };

namespace ShuntYard
{

    vector<string> tokenize(const string& expr);
    // Purpose: Changing a string of numeric operational inputs into tokens
    // for further analysis

    int getPrecedence(const string& op);
    // Purpose: Returns the precedence of operation with respect to mathematical
    // representations.

    ParenthesisAssociativity getAssociativity(const string& op);
    // Purpose: Returns an association of parenthesis (i.e., for example 5 (3)
    // would yield 5 * 3)

    vector<string> infixToPostfix(const vector<string>& token);
    // Purpose: changes the string of inputs into a more interpretable version
    // to be analyzed by another function (this is with respect to mathematical
    // precedence.)
}

#endif
