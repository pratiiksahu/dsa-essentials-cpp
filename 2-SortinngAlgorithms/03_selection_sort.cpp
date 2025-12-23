#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
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

    selectionSort(arr, n);

    cout << "After Sorting : ";
    printArray(arr, n);

    return 0;
}