#include <iostream>
#include <utility>          // for pair
using namespace std;

string reverseString (string &str) {
    int len = str.length ();
    string rev;
    
    for (int i = len-1; i >= 0; i--) {
        rev += str[i];                      // Appends a single character
    } 

    return rev;
}

pair<int, int> countVowels_Consonants (string &str) {
    int vowels = 0;
    int consonants = 0;
    int len = str.length ();
    
    for (int i = 0; i <= len-1; i++) {
        
        if (str[i] == 'a' || str[i] == 'A' ||
            str[i] == 'e' || str[i] == 'E' ||
            str[i] == 'i' || str[i] == 'I' ||
            str[i] == 'o' || str[i] == 'O' ||
            str[i] == 'u' || str[i] == 'U' ) {
            vowels++;
        } else if (isalpha (str[i])) {
            consonants++;
        }
    }
    
    return make_pair (vowels, consonants);
}

int main () {
    
    // Formatting
    cout << string (60, '=') << endl;
    cout << "\t\t\tString Manipulation\n";
    cout << string (60, '=') << endl;
    
    string str;
    cout << "\nEnter string: ";
    getline (cin, str);
    
    
    cout << "\n------------------------------------------------------------\n";
    // i) Reversing a string
    
    string reversedString = reverseString (str);
    cout << "Your reversed string: " << reversedString << endl;
    
    
    cout << "\n------------------------------------------------------------\n";
    // ii) Counting vowels
    
    auto counts = countVowels_Consonants (str);
    int vowelCounts = counts.first;
    int consonantCounts = counts.second;
    
    cout << "Number of vowels in the string '" << str << "': " << vowelCounts << endl;
    cout << "Number of consonants in the string '" << str << "': " << consonantCounts << endl;
    
    
    cout << "\n------------------------------------------------------------\n";
    // iii) Checking if the string is a palindrome
    
    if (reversedString == str) 
        cout << "The string '" << str << "' is Palindrome!" << endl;
        
    else 
        cout << "The string '" << str << "' is not Palindrome!" << endl;
    
	
	
	return 0;
}