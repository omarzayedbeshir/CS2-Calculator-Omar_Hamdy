#include <iostream>
#include <string>
#include "../include/shunting.h"
using namespace std;
using namespace ShuntYard;

int main()
{
    string expr;
    cout << "Enter an infix expression: ";
    getline(cin, expr);

    vector<string> tokens = tokenize(expr);
    vector<string> postfix = infixToPostfix(tokens);

    cout << "Postfix notation: ";
    for (const string& s : postfix)
        cout << s << " ";
    cout <<  endl;

    cout << "Result: "
         << evaluatePostfix(postfix) << endl;

    return 0;
}
