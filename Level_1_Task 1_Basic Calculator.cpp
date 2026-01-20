#include <iostream>
#include <stdexcept> // For standard exceptions
#include <string>
using namespace std;

// Objectives: i), ii), and iii)

int main () { 
	cout << "---------------------------------------------\n";
	cout << "\t Basic Calculator in C++ \n";
	cout << "---------------------------------------------\n";
	
	double num1, num2, res;
	string str;
	char myOperator;
	
	try { 
		
		// i) Implement user input
		cout << "Enter 1st no.: ";
		cin >> num1; 
		
		cout << "Enter Operator (+, -, *, /): ";
		cin >> str;
		
		// Takes only first char
		myOperator = str[0];

		cout << "Enter 2nd no.: ";
		cin >> num2;
		
		
		// ii) Implement output functions using switch case
		switch (myOperator) {
			case '+':
				res = num1 + num2;
				break;
				
			case '-':
				res = num1 - num2;
				break;
				
			case '*':
				res = num1 * num2;
				break;
			
			case '/':
				// iii) Proper handling of division by zero
				if (num2 == 0) throw runtime_error ("Cannot divide by zero!");
				
				res = num1 / num2;
				break;
				
			default:
			    throw invalid_argument ("Invalid operator! Use +, -, *, or /.");
		}
		
		cout << "Result: " << num1 << " " << myOperator << " " << num2 << " = " << res << endl;
		
	} catch (const exception &e) { 
		
		cout << "Error: " << e.what() << endl;
	} catch (...) { 
	    
		cout << "Unknown error occurred!" << endl;
	} 
	
	return 0;
} 