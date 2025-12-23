#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int a[] = {10, 9, 8 ,6, 5, 4, 3, 2, 12, 4, 0};
    int n = sizeof(a) / sizeof(int);

    // sort(a, a + n, compare);
    sort(a, a + n, greater<int>());

    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}