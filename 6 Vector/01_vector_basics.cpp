#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> a = {1, 2, 10, 12, 15};
    // a.pop_back();
    a.push_back(16);
    cout << "Size: " << a.size() << endl; // Size returns the number of elements
    cout << "Capacity: " << a.capacity() << endl; // Capacity returns the number of blocks currently in memory
    // Printing same as an array
    for (int i = 0; i < a.size(); i++) 
    {
        cout << a[i] << endl;
    }

    // Fill Constructor
    vector<int> visited(100, 0);

    return 0;
}