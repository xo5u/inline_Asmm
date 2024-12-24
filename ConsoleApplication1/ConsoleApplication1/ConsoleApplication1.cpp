#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>  // For sorting the array

using namespace std;

// Function to perform Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Target found
        }
    }
    return -1;  // Target not found
}

// Function to perform Binary Search (requires the array to be sorted)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  // Target not found
}

// Function to sort the array using std::sort
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    // Initialize random number generator
    srand(time(0));

    // Testing with various array sizes: 10, 100, 1000, 10000, 100000
    for (int n : {10, 100, 1000, 10000, 1000000000}) {
        vector<int> arr(n);

        // Fill the array with random numbers from 0 to 9
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10;
        }

        // Sequential Search Test
        auto start = chrono::high_resolution_clock::now();
        sequentialSearch(arr, 10);  // Searching for a number greater than 9 (worst case)
        auto end = chrono::high_resolution_clock::now();
        chrono::microseconds sequentialDuration = chrono::duration_cast<chrono::microseconds>(end - start);

        // Sorting Test
        start = chrono::high_resolution_clock::now();
        sortArray(arr);  // Sorting the array
        end = chrono::high_resolution_clock::now();
        chrono::microseconds sortingDuration = chrono::duration_cast<chrono::microseconds>(end - start);

        // Binary Search Test
        start = chrono::high_resolution_clock::now();
        binarySearch(arr, 10);  // Searching for a number greater than 9
        end = chrono::high_resolution_clock::now();
        chrono::microseconds binaryDuration = chrono::duration_cast<chrono::microseconds>(end - start);

        // Displaying the results for the current array size
        cout << "For array size = " << n << ":\n";
        cout << "Time for Sequential search : " << sequentialDuration.count() << " microseconds\n";
        cout << "Time for sorting : " << sortingDuration.count() << " microseconds\n";
        cout << "Time for Binary search: " << binaryDuration.count() << " microseconds\n";
        cout << "-----------------------------------------------\n";
    }

    return 0;
}
