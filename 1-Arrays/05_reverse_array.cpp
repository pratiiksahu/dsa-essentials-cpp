#include <iostream>
using namespace std;

// Problem : Reverse all the elements of a given array
void reverseArray(int a[], int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        // Swap
        // int temp = a[i];
        // a[i] = a[j];
        // a[j] = temp;
        swap(a[i], a[j]);

        i++;
        j--;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {10, 20, 30, 45, 50, 60, 70};
    int n = sizeof(a) / sizeof(int);
    reverseArray(a, n);
    printArray(a, n);

    return 0;
}