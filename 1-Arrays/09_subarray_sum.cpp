#include <iostream>
using namespace std;

// Problem : Find the subarry with largest sum
int subarraySumBrutForce(int a[], int n) {
    int largestSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int currSum = 0;
            for (int k = i; k <= j; k++) {
                currSum += a[k];
            }
            largestSum = max(largestSum, currSum);
            currSum = 0;
        }
    }
    return largestSum;
}

void subarrayPrefixMethod(int a[], int n) {

}

int main() {
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    cout << subarraySumBrutForce(a, n) << endl;
    return 0;
}