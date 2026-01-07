#include <iostream>
#include <limits>
#include <algorithm>
#include <chrono>
#include <cstring>
using namespace std;
using namespace std::chrono;

// Sorting Algorithms
// -------------------------------------------------------------

// Bubble Sort
void bubble_sort (int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


// Partition function
int partition (int arr[], int low, int high) {
	int pivot = arr[high];      // choose last element as pivot
	int i = low - 1;            // Index of smaller element

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;  // pivot index
}

// Quick Sort function
void quick_sort (int arr[], int low, int high) {
	if (low < high) {
		int pi = partition (arr, low, high);

		quick_sort (arr, low, pi - 1);   // left subarray
		quick_sort (arr, pi + 1, high);  // right subarray
	}
}


// Searching Algorithms
// -------------------------------------------------------------

// Linear Search
int linear_search (int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key)
			return i;   // element found
	}
	return -1;          // element not found
}


// Binary Search
int binary_search (int arr[], int n, int key) {
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2; // avoids overflow

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


void display (int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void inputData (int arr[], int len) {
	cout << "Enter data in the array:\n";
	for (int i = 0; i < len; i++) {
		cout << "Element [" << i + 1 << "]: ";
		cin >> arr[i];
	}
}


void sanitizeInput (int& choice) {
	if (!cin >> choice) {
		cin.clear ();
		cin.ignore (numeric_limits<streamsize> :: max (), '\n');
// 		cout << "Invalid input! Please enter a number\n";
	}
};

int main() {
	cout << "-------------------------------------------------------------\n";
	cout << "\t Sorting and Searching Algorithms";
	cout << "\n-------------------------------------------------------------\n";

	int len;
	cout << "Enter length of the array: ";
	cin >> len;

	int arr[len];

	inputData (arr, len);

	cout << "\nArray elements: ";
	display (arr, len);

	int choice = 0;
	while (choice != 4) {
		cout << "\nOperations to perform on the array.\n";
		cout << "\t1. Sorting\n\t2. Searching\n\t3. Measure Time Complexity of Bubble Sort & Quick Sort\n\t4. Exit\n";
		cout << "-------------------------------------------------------------\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

		sanitizeInput (choice);

		if (choice == 1) {
			cout << "\t1. Bubble Sort\n\t2. Quick Sort\n\n";
			cout << "Enter your choice: ";
			cin >> choice;

			sanitizeInput (choice);

			switch (choice) {
			case 1:
				cout << "Bubble Sort\n";
				bubble_sort (arr, len);
				cout << "Array sorted using Bubble Sort: \n";
				display (arr, len);
				break;

			case 2:
				cout << "Quick Sort\n";
				quick_sort (arr, 0, len - 1);
				cout << "Array sorted using Quick Sort: \n";
				display (arr, len);
				break;
			default:
				cout << "Invalid choice!\n";
			}
		}
		else if (choice == 2) {
			cout << "\t1. Linear Search\n\t2. Binary Search\n\n";
			cout << "Enter your choice: ";
			cin >> choice;

			sanitizeInput (choice);

			switch (choice) {
			case 1: {
				cout << "Linear Search\n";
				int key;
				cout << "Enter element to be found: ";
				cin >> key;
				int res = linear_search (arr, len, key);
				if (res != -1) {
					cout << "Element found at position " << (res + 1) << endl;
				} else {
					cout << "Element " << key << " not found!\n";
				}
				break;
			}

			case 2: {
				cout << "Binary Search\n";
				int key;
				cout << "Enter element to be found: ";
				cin >> key;
				bubble_sort (arr, len);
				int res = binary_search (arr, len, key);
				if (res != -1) {
					cout << "Element found at position " << (res + 1) << endl;
				} else {
					cout << "Element " << key << " not found!\n";
				}
				break;
			}

			default:
				cout << "Invalid choice!\n";
			}
		}
		else if (choice == 3) {
			int data_bubble[10000];
			memset(data_bubble, 0, sizeof(data_bubble));    // sets all elements to 0

			int data_quick[10000];
			memset(data_quick, 0, sizeof(data_quick));      // sets all elements to 0
            
			
			cout << "\nAnalyzing Time complexity...\n\n";

			// Measure Bubble Sort
			auto start_bubble = high_resolution_clock :: now();
			bubble_sort (data_bubble, 10000);
			auto end_bubble = high_resolution_clock :: now();
			auto duration_bubble = duration_cast<milliseconds> (end_bubble - start_bubble).count();

			// Measure Quick Sort
			auto start_quick = high_resolution_clock :: now();
			quick_sort (data_quick, 0, 10000 - 1);
			auto end_quick = high_resolution_clock :: now();
			auto duration_quick = duration_cast<milliseconds> (end_quick - start_quick).count();

			cout << "Bubble Sort took " << duration_bubble << " ms" << endl;
			cout << "Quick Sort took " << duration_quick << " ms" << endl;
		}
		else if (choice == 4) {
			cout << "Program exit successfully.\n";
		}
		else {
			cout << "Invalid choice! Please enter a number between 1 and 4.\n";
		}
	}

	return 0;
}