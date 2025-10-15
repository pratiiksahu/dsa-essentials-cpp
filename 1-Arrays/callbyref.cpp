#include <iostream>
using namespace std;

void printArray(int *a, int n) {
    a[7] = 100;

    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7 ,8};
    int n = sizeof(a) / sizeof(int); // 32 / 4 = 8

    printArray(a, n);

    cout << "Inside main function" << endl;

    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}