#include <iostream>
#include "../include/calculator.h"

using namespace std;


int main() {

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
        cout << "9- Exit" << endl;
        cout << "Enter your desired operation number: ";
        cin >> choice;

        if (choice == 9)
            break;

        switch(choice) {
            case 1:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << add(x, y) << endl;
                break;
            case 2:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << subtract(x, y) << endl;
                break;
            case 3:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << multiply(x, y) << endl;
                break;
            case 4:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << divide(x, y) << endl;
                break;
            case 5:
                int x;
                cout << "Enter the number: ";
                cin >> x;
                cout << "Result: " << factorial(x) << endl;
                break;
            case 6:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << GCD(x, y) << endl;
                break;
            case 7:
                int x, y;
                cout << "Enter the first number: ";
                cin >> x;
                
                cout << "Enter the second number: ";
                cin >> y;
                cout << "Result: " << LCM(x, y) << endl;
                break;
            case 8:
                int x, y;
                cout << "Enter the starting number: ";
                cin >> x;
                
                cout << "Enter the ending number: ";
                cin >> y;
                cout << "Result: " << random(x, y) << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }
        
    }
    return 0;
}