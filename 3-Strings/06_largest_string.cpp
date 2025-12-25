#include <iostream>
using namespace std;

// Problem :  Read N strings and print the largest string. Each string can have upto 1000 characters.

int main() {
    char sentence[1000];
    char largest[1000];
    int n;
    cin >> n;
    cin.get(); // Read the unwanted next line character from buffer

    while (n--) {
        cin.getline(sentence, 1000);
        if (strlen(sentence) > strlen(largest)) {
            strcpy(largest, sentence);
        }
    }
    cout << largest << endl;
    
    return 0;
}