#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Size of Vector : " << arr.size() << endl;
    cout << "Capacity of Vector : " << arr.capacity() << endl;

    cout << "Adding 1 more element" << endl;

    arr.push_back(6);

    cout << "Size of Vector : " << arr.size() << endl;
    cout << "Capacity of Vector is doubled : " << arr.capacity() << endl;

    arr.pop_back();
    arr.push_back(7);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    cout << "***********************" << endl;

    // Fill back constructor
    vector<int> visited(10, 7);
    for (int i = 0; i < visited.size(); i++) {
        cout << visited[i] << endl;
    }

    return 0;
}