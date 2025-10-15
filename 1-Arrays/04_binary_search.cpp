#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int k) {
    int start = 0;
    int end = n;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] == k) {
            return mid;
        }
        else if (a[mid] > k) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
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

    int index = binarySearch(a, n, key);
    if (index != -1) {
        cout << key << " is present at index " << index << endl;
    }
    else {
        cout << key << " is not found! " << endl;
    }
}
