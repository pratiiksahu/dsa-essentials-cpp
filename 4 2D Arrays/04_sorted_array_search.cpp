#include <iostream>
using namespace std;

// Problem : Write a function that searches for an element in row wise and col wise in a 2D sorted array.
pair<int, int> stairCaseSearch (int a[][4], int row, int col, int key) {
    // Search starts from this co-oridnate because if we go left then we get smaller elements and if we go down then we get larger elements.
    int i = 0;
    int j = col - 1;

    // Return (-1, -1) if key is greater than the largest element in the matrix
    if (key > a[row - 1][col - 1]) {
        return {-1, -1};
    }

    while (i < row and j >= 0) {
        if (a[i][j] == key) {
            return {i, j};
        }
        else if (key > a[i][j]) {
            i++;
        }
        else if (key < a[i][j]) {
            j--;
        }
    }
    return {-1, -1};
}

int main() {
    //2D Row & Column Wise Sorted Array
	int arr[][4] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};

    int n = 4,m=4; 

    pair<int,int> coords = stairCaseSearch(arr,n,m,50);
    cout<< coords.first<<" "<<coords.second <<endl;
    return 0;  
}