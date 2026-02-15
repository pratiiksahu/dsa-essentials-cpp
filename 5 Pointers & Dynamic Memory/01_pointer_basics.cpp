#include <iostream>
using namespace std;

int main() {
    int x  = 10;
    float y = 5.5;

    // Address of x
    cout << &x << endl;
    int *xptr = &x;
    // Value of xptr == Address of x
    cout << xptr << endl;
    // Address of pointer variable xptr
    cout << &xptr << endl;
    // Pointer to a pointer variable
    int **xxptr = &xptr;
    // Value of xxptr == Address of xptr
    cout << xxptr << endl;

    return 0;
}