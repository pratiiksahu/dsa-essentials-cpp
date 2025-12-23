// Given a sentence count the number of digit, alphabet and space in the sentence.
#include <iostream>
using namespace std;

int main() {
    int alpha = 0;
    int space = 0;
    int num = 0;
    char ch = cin.get();

    while (ch != '\n') {
        if (ch >= '0' and ch <= '9') {
            num++;
        } 
        else if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')) {
            alpha++;
        } 
        else if (ch == ' ' or ch == '\t') {
            space++;
        }
        else {
            cout << "Invalid Character : " << ch;
        }
    }
    cout << "Count of Alphabets : " << alpha << endl;
    cout << "Count of Number : " << num << endl;
    cout << "Count of Spaces : " << space << endl;

    return 0;
}