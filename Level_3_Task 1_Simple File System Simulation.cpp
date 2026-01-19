#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void sanitize_input (int n);

class SimpleFileSystem {
public:
    vector<string> filenames;

    SimpleFileSystem () {
        loadFilenames ();
    }

    void loadFilenames () {
        filenames.clear ();
        for (const auto& entry : fs::directory_iterator (".")) {
            if (entry.is_regular_file () && entry.path ().extension () == ".txt") {
                filenames.push_back (entry.path ().filename ().string ());
            }
        }
    }

    void createFile (const string& filename, const string& content) {
        ofstream outFile (filename);
        outFile << content;
        outFile.close ();
        filenames.push_back (filename);
        cout << "File '" << filename << "' created.\n";
    }

    void deleteFile(const string& filename) {
        if (fs::remove (filename)) {
            cout << "File '" << filename << "' deleted.\n";
            // Remove from list
            filenames.erase (remove (filenames.begin (), filenames.end (), filename), filenames.end ());
        } else {
            cout << "File '" << filename << "' not found.\n";
        }
    }

    void readFile (const string& filename) {
        ifstream inFile (filename);
        if (inFile) {
            cout << "Content of '" << filename << "':\n";
            string line;
            while (getline (inFile, line)) {
                cout << line << "\n";
            }
        } else {
            cout << "File '" << filename << "' not found.\n";
        }
    }

    void listFiles () {
        cout << "Files:\n";
        for (const auto& f : filenames) {
            cout << "- " << f << "\n";
        }
    }
};

int main () {
    SimpleFileSystem fs;
    int command;

    while (true) {
        cout << "\n----- Simple File System Simulation in C++ -----\n";
        cout << "------------------------------------------------\n";
        cout << "\t1. Create\n\t2. Delete\n\t3. Read\n\t4. List\n\t5. Exit\n";
        cout << "\nPlease enter commands: ";
        cin >> command;
        sanitize_input (command);       // Input Validation

        if (command == 1) {
            string filename, content;
            cout << "Enter filename: ";
            cin >> filename;
            cout << "Enter content: ";
            cin.ignore (); // ignore leftover newline
            getline (cin, content);
            fs.createFile (filename, content);
        } else if (command == 2) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            fs.deleteFile (filename);
        } else if (command == 3) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            fs.readFile (filename);
        } else if (command == 4) {
            fs.listFiles ();
        } else if (command == 5) {
            cout << "\n\nProgram exit successfully.\n";
            break;
        } else {
            cout << "Unknown command.\n";
        }
        // Reload filenames after delete/create
        fs.loadFilenames ();
    }

    return 0;
}

void sanitize_input (int n) {
    if (!cin >> n) {
        cout << "Invalid command! Please enter between 1 to 5.\n";
        cin.clear ();       // Clear error state
        cin.ignore ();      // Remove bad input
        return;
    }
}