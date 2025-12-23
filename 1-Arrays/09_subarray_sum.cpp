#include <iostream>
using namespace std;

// Problem : Find the subarry with largest sum
int subArraySumBrutForce(int a[], int n) {
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

int subArraySumPrefix(int a[], int n) { 
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

int subArraySumKadene(int a[], int n) {
    int currSum, largestSum = 0;

    for (int i = 0; i < n; i++) {
        currSum = currSum + a[i];
        // reset current sum if element is negative
        if (a[i] < 0) {
            currSum = 0;
        }
        largestSum = max(currSum, largestSum);
    }
    return largestSum;
}

int main() {
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    cout << "Largest Sub Array Sum using BruteForce Approach : " << subArraySumBrutForce(a, n) << endl;
    cout << "Largest Sub Array Sum using Prefix Array Approach : " << subArraySumPrefix(a, n) << endl;
    cout << "Largest Sub Array Sum using Kadene's Approach : " << subArraySumPrefix(a, n) << endl;
    return 0;
}