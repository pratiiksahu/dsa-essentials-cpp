#include <iostream>
using namespace std;

// return the index for the given element k if present else -1
int linearSearch(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            return i;
        }
    }
    return -1;
}

int main () {
    int a[]= {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(a) / sizeof(int);

    int key;
    cout << "Enter the key : ";
    cin >> key;

    int index = linearSearch(a, n, key);
    if (index != -1) {
        cout << key << " is present at index " << index << endl;
    }
    else {
        cout << key << " is not found! " << endl;
    }
}