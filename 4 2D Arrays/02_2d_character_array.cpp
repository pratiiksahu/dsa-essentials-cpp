#include <iostream>
using namespace std;

int main() {
    char a[][10] = {"one", "two", "three", "four", "five", "six"};

    // Print all the strings of the 2D-Char Array
    for (int i = 0; i < 6; i++) {
        cout << a[i] << endl;
    }
    return 0;
}