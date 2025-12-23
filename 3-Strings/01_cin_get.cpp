#include <iostream>
using namespace std;

int main() {
    char sentence[1000];
    int len = 0;
    char temp = cin.get();

    while (temp != '#' && len < 1000) {
        sentence[len++] = temp;
        temp = cin.get();
    }
    sentence[len] = '\0';

    cout << sentence << endl;

    return 0;
}