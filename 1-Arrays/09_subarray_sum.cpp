#include <iostream>
using namespace std;

// Problem : Find the subarry with largest sum
int subarraySumBrutForce(int a[], int n) {
    int largestSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
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

int subarraysumPrefix(int a[], int n) { 
    int prefixArray[100] = {0};
    int largestSubArraySum = 0;
    int subArraySum = 0;
    prefixArray[0] = a[0];

    for (int i = 1; i < n; i++) {
        prefixArray[i] = prefixArray[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            subArraySum = (i > 0) ? prefixArray[j] - prefixArray[i - 1] : prefixArray[j];
            largestSubArraySum = max(largestSubArraySum, subArraySum);
        }
    }
    return largestSubArraySum;
}

int main() {
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    cout << "Largest Sub Array Sum using BruteForce Approach : " << subarraySumBrutForce(a, n) << endl;
    cout << "Largest Sub Array Sum using Prefix Array Approach : " << subarraysumPrefix(a, n) << endl;
    return 0;
}