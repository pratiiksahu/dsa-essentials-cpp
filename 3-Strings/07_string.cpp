#include <iostream>
using namespace std;

int main() {
    int n;
    vector<string> stringList;
    string s;

    cin >> n;
    cin.get();

    while (n--) {
        getline(cin, s);
        stringList.push_back(s);
    }

    for (string s: stringList) {
        cout << s << endl;
    }

    return 0;
}