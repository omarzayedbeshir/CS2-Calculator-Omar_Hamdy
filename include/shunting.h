#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum ParenthesisAssociativity { LEFT, RIGHT };

/* Purpose: Changing a string of numeric operational inputs into tokens
   for further analysis. */
vector<string> tokenize(const string& expr);

/* Purpose: Returns the precedence of operation with respect to mathematical
   representations. */
int getPrecedence(const string& op);

/* Purpose: Returns an association of parenthesis (i.e., for example 5 (3)
   would yield 5 * 3) */
ParenthesisAssociativity getAssociativity(const string& op);

/* Purpose: changes the string of inputs into a more interpretable version
   to be analyzed by another function (this is with respect to mathematical
   precedence.) */
vector<string> infixToPostfix(const vector<string>& token);

// Purpose: returns the value of the postfix expression after evaluation.
double evaluatePostfix(const vector<string>& postFix);
