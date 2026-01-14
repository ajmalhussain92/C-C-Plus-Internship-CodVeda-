#include <iostream>
#include <vector>
#include <algorithm> // for std::copy
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort implementation
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data(10000);
    // Fill the data with random values
    for (int& val : data) {
        val = rand() % 100000;
    }

    vector<int> data_bubble = data;
    vector<int> data_quick = data;

    // Measure Bubble Sort
    auto start_bubble = high_resolution_clock::now();
    bubbleSort(data_bubble);
    auto end_bubble = high_resolution_clock::now();
    auto duration_bubble = duration_cast<milliseconds>(end_bubble - start_bubble).count();

    // Measure Quick Sort
    auto start_quick = high_resolution_clock::now();
    quickSort(data_quick, 0, data_quick.size() - 1);
    auto end_quick = high_resolution_clock::now();
    auto duration_quick = duration_cast<milliseconds>(end_quick - start_quick).count();

    cout << "Bubble Sort took " << duration_bubble << " ms" << endl;
    cout << "Quick Sort took " << duration_quick << " ms" << endl;

    return 0;
}