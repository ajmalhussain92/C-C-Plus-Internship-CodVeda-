#include <iostream>
#include <limits> 	// for numeric_limits
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    
    while (true) {
        if (cin >> number) {
            // Successfully read an integer
            break;
        } else {
            // Invalid input, clear error state
            cin.clear();
            // Ignore the rest of the line
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
            cout << "Invalid input. Please enter a valid integer: ";
        }
    }

    cout << "You entered: " << number << endl;
    return 0;
}