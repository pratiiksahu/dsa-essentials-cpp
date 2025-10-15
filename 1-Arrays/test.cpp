#include <iostream>
using namespace std;

void Sum(int a, int b, int *sum) {
    *sum = a + b;
}

int main() {
    cout << "Hello World" << endl;
    int *sum = (int*)malloc(sizeof(int));
    Sum(8, 4, sum);
    cout << *sum;
    return 0;
}