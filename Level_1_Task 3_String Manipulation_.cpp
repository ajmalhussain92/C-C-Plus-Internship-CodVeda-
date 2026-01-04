#include <iostream>
#include <vector>
#include <utility>          // for std::pair
using namespace std;

vector<char> reverseString (vector<char> str) {
    int len = str.size();
    vector<char> rev;
    
    for (int i = len-1; i >= 0; i--) {
        rev.push_back(str[i]);
    } 

    return rev;
}

pair<int, int> countVowels (vector<char> &str) {
    int vowels = 0;
    int consonants = 0;
    int len = str.size();
    
    for (int i = 0; i <= len-1; i++) {
        
        if (str[i] == 'a' || str[i] == 'A' ||
            str[i] == 'e' || str[i] == 'E' ||
            str[i] == 'i' || str[i] == 'I' ||
            str[i] == 'o' || str[i] == 'O' ||
            str[i] == 'u' || str[i] == 'U' ) {
            vowels++;
        } else if (isalpha(str[i])) {
            consonants++;
        }
    }
    
    return make_pair (vowels, consonants);
}

int main () {
    
    cout << string(60, '=') << endl;
    cout << "\t\t\tString Manipulation\n";
    cout << string(60, '=') << endl;
    
    
    // Use character array
    vector<char> str = {'m', 'a', 'd', 'a', 'm'};
    
    
    // Making string from character array
    
     string myStr(str.begin(), str.end());
    
    cout << "String extracted: " << myStr << endl;
    
    
    
    cout << "\n------------------------------------------------------------\n";
    // i) Reversing a string
    
    vector<char> reversedString = reverseString(str);
    cout << "Your reversed string: ";
    
    for (char ch : reversedString) {
        cout << ch ;
    }
    
    
    
    cout << "\n\n-----------------------------------------------------------\n";
    // ii) Counting vowels
    
    auto counts = countVowels (str);
    int vowelCounts = counts.first;
    int consonantCounts = counts.second;
    
    cout << "Number of vowels in the string: " << vowelCounts << endl;
    cout << "Number of consonats in the string: " << consonantCounts << endl;
    
    
    
    cout << "\n------------------------------------------------------------\n";
    // iii) Checking if the string is a palindrome
    
    if (reversedString == str) 
        cout << "The string '" << myStr << "' is Palindrome!" << endl;
        
    else 
        cout << "The string '" << myStr << "' is not Palindrome!" << endl;
    
    
	return 0;
}