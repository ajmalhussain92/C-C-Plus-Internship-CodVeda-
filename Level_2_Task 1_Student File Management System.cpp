#include <iostream>
#include <vector>
#include <fstream>
#include <limits> 		// For numeric_limits
#include <string>
using namespace std;


// i) Use struct to represent student data (name, ID, grades)
struct  Student {
	string name;
	int id;
	char grade;
};

// ii) Implement file handling to save and load records
// Save Students data to file
void saveStudentsDataToFile (const vector<Student>& students, const string& filename);

// Load Students data from file
void loadStudentsDataFromFile (vector<Student>& students, const string& filename);


// iii)  CRUD (Create, Read, Update, Delete) operations
Student addStudent ();
void displayAllStudents (const vector<Student>& students);
void searchStudent (const vector<Student>& students);
void updateStudent (vector<Student>& students);
void deleteStudent (vector<Student>& students);



int main () {
	cout << "---------------------------------------\n";
	cout << "\t Student Management System\n";
	cout << "---------------------------------------\n";

	vector<Student> students;
	string filename = "students.txt";

	// Load existing data
	loadStudentsDataFromFile (students, filename);

	int choice = 0;
	while (choice != 6) {
	    cout << "\nChoices:\n\t1. Add Student\n\t2. Display All Students\n\t3. Search Student\n\t4. Update Student\n\t5. Delete Student\n\t6. Exit\n";
	    cout << "---------------------------------------\n";
		cout << "\nEnter choice: ";
		cin >> choice;

		if (!cin >> choice) {
			cin.clear ();		// Invalid input, clear error state
			cin.ignore (numeric_limits<streamsize> :: max(), '\n');
		}

		switch (choice) {
		case 1: {
			Student newStudent = addStudent ();
			students.push_back (newStudent);	// Save the 'newStudent' in the vector
			break;
		}

		case 2:
			displayAllStudents (students);
			break;

		case 3:
			searchStudent (students);
			break;

		case 4:
			updateStudent (students);
			break;

		case 5:
			deleteStudent (students);
			break;

		case 6:
			saveStudentsDataToFile (students, filename);	// Save before exiting
			cout << "Data saved. Exiting...\n";
			break;

		default:
			cout << "Invalid choice! Please enter between 1 to 6.\n";
		}
	}

	return 0;
}


// Implementation of CRUD operations

Student addStudent () {
	Student s;      // create a new Student object
	cout << "Enter credentials of the Student: \n\n";
	cout << "Name: ";
	cin.ignore ();   // to ignore leftover newline
	getline (cin, s.name);
	cout << "ID: ";
    cin >> s.id;
	cout << "Grade: ";
	cin >> s.grade;

	return s;       // return the newly created student struct
}

void displayAllStudents (const vector<Student>& students) {
    cout << "\nName\tID\tGrade \n";
	for (const auto& s : students) {
		cout << s.name << "\t" << s.id << "\t" << s.grade << endl;
	}
}

void searchStudent (const vector<Student>& students) {
    if (students.empty()) {
        cout << "Student is empty.\n";
        return;
    }
    
	int id;
	cout << "Search student by ID: ";
	cin >> id;

	bool found = false;     // To track if the student was found
	for (const auto& s : students) {
		if (id == s.id) {
			cout << "Student found:\n";
			cout << "Name: " << s.name << "\tID: " << s.id << "\tGrade: " << s.grade << endl;
			found = true;
			break;      // Exit loop after finding the student
		}
	}

	if (!found) {
		cout << "Student with ID " << id << " not found.\n";
	}
}

void updateStudent (vector<Student>& students) {
    if (students.empty()) {
        cout << "Student is empty.\n";
        return;
    }
    
	int id;
	cout << "Update student by ID: ";
	cin >> id;

	string name;
	char grade;

	bool found = false;     // To track if the student was found
	for (auto& s : students) {
		if (id == s.id) {
			// Display current info
			cout << "Name: " << s.name << "\tID: " << s.id << "\tGrade: " << s.grade << endl;

			// Input new data
			cout << "Enter name: ";
			cin.ignore ();
			getline (cin, name);

			cout << "Enter grade: ";
			cin >> grade;

			// Update the student data
			s.name = name;
			s.grade = grade;
			cout << "Student's data has been updated.\n";
			found = true;
			break;      // Exit loop after updating
		}
	}

	if (!found) {
		cout << "Student with ID " << id << " not found.\n";
	}
}

void deleteStudent (vector<Student>& students) {
    if (students.empty()) {
        cout << "Student is empty.\n";
        return;
    }
    
	int id;
	cout << "Delete student by ID: ";
    cin >> id;
    
	bool found = false;     // To track if the student was found
	for (auto it = students.begin(); it != students.end(); ++it) { 
		if (id == it -> id) {
		    // Display current info
			cout << "Student found:\n";
			cout << "Name: " << it -> name << "\tID: " << it -> id << "\tGrade: " << it -> grade << endl;
			
			string ans;
			cout << "\nConfirm Delete student? (yes/y to confirm): ";
			cin.ignore ();
			getline (cin, ans);
			
			// Convert answer to lowercase for easier comparison (optional)
            for (auto& c : ans) c = tolower(c);
			
			if (ans == "yes" || ans == "y") {
			    students.erase (it);
			    cout << "Student has been deleted.\n";
			} else {
			    cout << "Delete aborted.\n";
			}
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Student with ID " << id << " not found.\n";
	}
}

void saveStudentsDataToFile (const vector<Student>& students, const string& filename) {
	ofstream MyFile (filename);       // Create and open a text file

	if (!MyFile) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (const auto& s : students) {
		MyFile << s.name << "," << s.id << "," << s.grade << "\n";
	}
    
	MyFile.close ();
}

void loadStudentsDataFromFile (vector<Student>& students, const string& filename) {
	ifstream MyReadFile (filename);

	if (!MyReadFile) {
		return;     // If file doesn't exist, just return
	}

	string line;

	while (getline (MyReadFile, line)) {
		Student s;
		size_t pos1 = line.find (',');
		size_t pos2 = line.find (',', pos1 + 1);
        
		if (pos1 != string :: npos && pos2 != string :: npos) { 
			s.name = line.substr(0, pos1);
			s.id = stoi (line.substr (pos1 + 1, pos2 - pos1 - 1));
			s.grade = line.back ();
			
			students.push_back (s);
		}
	}
} 