#include <iostream>
using namespace std;

int main() {
    int x = 0;
    int y = 0;

    char ch = cin.get();
    
    while (ch != '\n') {
        if (ch == 'N' or ch == 'n') {
            y++;
        }
        else if (ch == 'S' or ch == 's') {
            y--;
        }
        else if (ch == 'E' or ch == 'e') {
            x++;
        }
        else if (ch == 'W' or ch == 'w') {
            x--;
        }
        else {
            cout << "invalid character " << ch << endl;
        }
        ch = cin.get();
    }

    cout << "X & Y co-ordinates are : " << x << ", " << y << endl;

    // @todo : Update the shortest path for all quadrents
    if (x > 0 and y > 0) {
        while (x > 0) {
            cout << "E";
            x--;
        }
        while (y > 0) {
            cout << "N";
            y--;
        }
    }
    cout << endl;

    return 0;
}