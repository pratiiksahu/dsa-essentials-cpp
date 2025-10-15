#include <iostream>
using namespace std;

int main() {
    int a[100] = {-1};
    int n = 0;

    cout << "Enter number students : ";
    // cin >> n;

    // // Array Input
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }

    // Array Output
    for(int i = 0; i < 100; i++) {
        cout << a[i] << ", ";
    }

    cout << endl;

    return 0;
}