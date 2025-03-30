#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum ParenthesisAssociativity { LEFT, RIGHT };
// Added for parenthesis distinctions.

vector<string> tokenize(const string& expr);
// Precondtion: argument must be of type string and an unprocessed operation.
// Purpose: Changing a string of numeric operational inputs into tokens
//          for further analysis.

int getPrecedence(const string& op);
// Purpose: Returns the precedence of operation with respect to mathematical
//          representations. It acts as a helper function.

ParenthesisAssociativity getAssociativity(const string& op);
// Purpose: Returns an association of parenthesis (i.e., for example 5 (3)
//          would yield 5 * 3). Acts as a helper function.

vector<string> infixToPostfix(const vector<string>& token);
// Precondition: Has to be a string already processed from the tokenize function
//               or a similar algorithm.
// Purpose: changes the string of inputs into a more interpretable version
//          to be analyzed by another function (this is with respect to 
//          mathematical precedence.)

double evaluatePostfix(const vector<string>& postFix);
// Precondition: Has to be a postFix vector expression processed by the
//               infixToPostFix function or a similar algorithm.
// Purpose: returns a value of the postfix expression after evaluation.
