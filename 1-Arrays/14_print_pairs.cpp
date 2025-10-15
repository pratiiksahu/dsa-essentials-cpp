#include <iostream>
using namespace std;

// Problem : Print all pairs of an array
void printAllPairs(int a[], int n) {
    // Printing all pairs using nested loop
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << a[i] << ", " << a[j] << endl;
        }
    }
}

int main() {
    int a[] = {10, 20, 30, 40};
    int n = sizeof(a) / sizeof(int);
    printAllPairs(a, n);

    return 0;
}