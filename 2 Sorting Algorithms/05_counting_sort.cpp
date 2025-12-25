#include <iostream>
#include <climits>
using namespace std;

void countingSort(int a[], int n) {
    // Initialize the largest variable with the smallest integer
    int largest = INT_MIN;

    // Find the largest integer
    for (int i = 0; i < n; i++) {
        largest = max(largest, a[i]);
    }

    cout << "Largest Element : " << largest << endl;

    // Create a frequency array dynamically with the size of largest element
    vector<int> frequency(largest + 1, 0);

    // Update frequency array
    for (int i = 0; i < n; i++) {
        frequency[a[i]]++;
    }

    // Update the input array by printing occurrences of all elements. This will result in sorted array.
    int j = 0; // Counter for original input array
    for (int i = 0; i < frequency.size(); i++) {
        while (frequency[i] > 0 and j < n) {
            a[j] = i;
            frequency[i]--;
            j++;
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 4, 5, 6, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before Sorting : ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "After Sorting : ";
    printArray(arr, n);

    return 0;
}