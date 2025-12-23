#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    bool isSwapRequired = false;

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j + 1]);
                isSwapRequired = true;
            }
        }
        // Array is already sorted
        if (!isSwapRequired) {
            break;
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
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before Sorting : ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "After Sorting : ";
    printArray(arr, n);

    return 0;
}