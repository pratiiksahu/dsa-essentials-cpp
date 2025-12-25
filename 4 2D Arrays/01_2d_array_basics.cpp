#include <iostream>
using namespace std;

void input(int a[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }
}

void print(int a[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[100][100];
    // n -> Rows, m -> Columns
    int n, m;
    cin >> n >> m;

    input(a, n, m);
    print(a, n, m);

    return 0;
}