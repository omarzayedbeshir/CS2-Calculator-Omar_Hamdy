#include <iostream>
#include "../include/calculator.h"
#include "../include/shunting.h"
#include <vector>
#include <string>

using namespace std;


int main() {
    
    int x, y;
    string exp;
    vector<string> tokens, postfix;

    while (true) {

        int choice;
        cout << "1- Add" << endl;
        cout << "2- Subtract" << endl;
        cout << "3- Multiply" << endl;
        cout << "4- Divide" << endl;
        cout << "5- Factorial" << endl;
        cout << "6- GCD" << endl;
        cout << "7- LCM" << endl;
        cout << "8- Random" << endl;
        cout << "9- Expression Parser" << endl;
        cout << "10- Exit" << endl;
        cout << "Enter your desired operation number: ";
        cin >> choice;

        if (choice == 10)
            break;

        switch(choice) {
            case 1:
                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << add(x, y) << endl;
                break;
            case 2:

                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << subtract(x, y) << endl;
                break;
            case 3:
                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << multiply(x, y) << endl;
                break;
            case 4:

                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << divide(x, y) << endl;
                break;
            case 5:

                cout << "Enter the number: ";
                cin >> x;
                cout << "Result: " << factorial(x) << endl;
                break;
            case 6:

                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << GCD(x, y) << endl;
                break;
            case 7:

                cout << "Enter the first number: ";
                cin >> x;

                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << LCM(x, y) << endl;
                break;
            case 8:

                cout << "Enter the starting number: ";
                cin >> x;

                cout << "Enter the ending number: ";
                cin >> y;
                cout << "Result: " << random(x, y) << endl;
                break;
            case 9:
                cout << "Enter an expresion to evaluate: ";
                getline(cin, exp);
                tokens = tokenize(exp);
                postfix = infixToPostfix(tokens);
                double result = evaluatePostfix(postfix);
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }

    }
    return 0;
}
