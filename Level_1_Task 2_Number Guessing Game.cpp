#include <iostream>
#include <random>		// for rand() and srand()
#include <ctime>
using namespace std;

// Number Guessing Game
// Objectives: i), ii), and iii)

int generateRandomNumber () { 
	srand (time (0));     // Seed the random generator
	
	// To get a number in a specific range, say 1 to 10:
    int lower = 1;
    int upper = 10;
    int rand_num = lower + rand() % upper;		// i) Use the rand() function to generate random numbers
    
    return rand_num;
}

int main () { 
	
	cout << "--------------------------------------------------------\n";
	cout << "\t\t Number Guessing Game\n";
	cout << "--------------------------------------------------------\n";
	
	cout << "A number is chosen between 1 and 10." << endl << endl;
	cout << "You have 5 attempts to guess the correct number." << endl;
	
	int rand_num = generateRandomNumber ();
	
	int guess;
	int curAttempts = 0, maxAttempts = 5;
	
	
	//  ii) Implemented do-while loop to allow multiple attempts.
	do {
		cout << "Enter your guess: ";
		cin >> guess;
		
		if (guess != rand_num) {
			
			curAttempts++;
			
			if (curAttempts == maxAttempts)
				cout << "You've exhausted all attempts. The correct number was " << rand_num << endl << endl;
			else 
				cout << "You have " << (maxAttempts - curAttempts) << " attempts left" << endl << endl;
				
				// iii) Provide feedback on whether the guess was too high or too low
				if (guess < rand_num)
					cout << "Your guess, " << guess << ", is too low." << endl << endl;
				else 
					cout << "Your guess, " << guess << ", is too high." << endl << endl;
			
		} else { 
			cout << "It took you " << curAttempts + 1 << " attempts to guess my number, which was " << rand_num << endl << endl;
			cout << "Thanks for playing game! Have a nice day!";
			return 0;
		}
		
	} while (curAttempts != maxAttempts);
	
	
	return 0;
}