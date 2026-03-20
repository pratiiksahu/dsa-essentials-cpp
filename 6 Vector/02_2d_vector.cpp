#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 2D Vector -> Jagged Array
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10}
    };

    arr[0][0] += 10;

    // Iterating through 2D Vector
    cout << "Iterating 2D Vector using Nested Loop" << endl;
    for(int i=0; i < arr.size(); i++) {
        for(int j=0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Iterating 2D Vector Using Range-based Loops (Modern C++)" << endl;
    for(vector<int> row : arr) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}