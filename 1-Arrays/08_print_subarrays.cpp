#include <iostream>
using namespace std;

// Problem : Print all subarrays of a given array.
void printSubArrays(int a[], int n) {
    // Printing all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(int);
    printSubArrays(a, n);
    return 0;
}