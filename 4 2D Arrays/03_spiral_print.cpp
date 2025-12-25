#include <iostream>
using namespace std;

void spiralPrint(int a[][10], int row, int col) {
    int startRow = 0;
    int endCol = col - 1;
    int endRow = row - 1;
    int startCol = 0;

    while ((startCol <= endCol) and (startRow <= endRow)) {
        // Start Row
        for (int i = 0; i <= endCol; i++) {
            cout << a[startRow][i] << " ";
        }
        // End Col
        for (int i = startRow + 1; i <= endRow; i++) {
            cout << a[i][endCol] << " ";
        }
        // End Row
        for (int i = endCol - 1; i >= startCol; i--) {
            if (startRow == endRow) {
                break;
            }
            cout << a[endRow][i] << " ";
        }
        // Start Col
        for (int i = endRow - 1; i >= startRow + 1; i--) {
            if (startCol == endCol) {
                break;
            }
            cout << a[i][startCol] << " ";
        }
        // Increment counters
        startCol++;
        startRow++;
        endCol--;
        endRow--;
    }
}

int main() {
    int n, m;
    int a[10][10] = {
        { 1,  2,  3,  4},
        { 12, 13, 14, 5},
        { 11, 16, 15, 6},
        { 10,  9,  8, 7}
    };
    n = m = 4;

    spiralPrint(a, n, m);
    
    return 0;
}