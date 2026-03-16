#include <iostream>
using namespace std;

// Pass by reference using reference variables
void applyTax(float &income) {
    float tax = 0.10;
    income = income - income * tax;
}

// Pass by reference using pointer variable
void applyTax(float *income) {
    *income = *income - *income * 0.20;
}

int main() {
   float income = 100000;
   applyTax(income);  // reference
   applyTax(&income); // pointer

   cout << income << endl;
}