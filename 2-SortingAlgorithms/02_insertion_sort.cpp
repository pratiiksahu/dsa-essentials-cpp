#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int j = 1; j < n; j++) {
        // insert the key in the sorted sequence a[1, 2, ..., (j - 1)]
        int key = a[j];
        int i = j - 1;
        
        // loop and find the correct index where the key should be inserted
        while (i > 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before Sorting : ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "After Sorting : ";
    printArray(arr, n);

    return 0;
}