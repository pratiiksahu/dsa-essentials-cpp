#include <iostream>
using namespace std;

int main() {
    char a[100] = "apple";
    char b[100];

    cout << "Length of a : " << strlen(a) << endl;

    strcpy(b, a);

    cout << b << endl;

    cout << strcmp(a, b) << endl;

    return 0;
}