#include <iostream>
using namespace std;

int main() {
    char a[100] = "apple";
    char b[100];

    cout << "Length of a : " << strlen(a) << endl;

    strcpy(b, a);

    cout << b << endl;

    cout << strcmp(a, b) << endl;

    char web[] = "www.";
    char domain[] = "dsa-essentials.com";

    strcpy(b, strcat(web, domain));

    cout << b << endl;

    cout << strcmp(a, b) << endl;

    return 0;
}