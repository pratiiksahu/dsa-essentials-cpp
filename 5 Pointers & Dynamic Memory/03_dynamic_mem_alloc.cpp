#include <iostream>
using namespace std;

void create1DArray() {
    int n = 10;
    // Dynamic Array
    int *arr = new int[n];
    cout << arr << endl;

    for (int i = 0; i < n; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;

    // Delete the allocated memory from heap
    cout << arr << endl;
    // cout << arr[2] << endl; -> Should never be done
}

int** create2DArray(int rows, int cols) {
    int** arr = new int*[rows];
    int value = 0; // used for initializing 2D array

    // Allocate memory for each row
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // initialize array with increasing list of numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
            value++;
        }
    }
    // Memory created in heap so we can still use this space
    return arr;
}

int main()
{
    // create1DArray();
    int row = 3;
    int col = 3;
    int** arr = create2DArray(row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j< col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}