#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector<int> v(5);
    v.pushback(1);
    v.pushback(2);
    v.pushback(3);
    v.pushback(4);
    v.pushback(5);
    v.pushback(6);
    v.popback();

    cout << "Front : " <<  v.front() << endl;
    cout << "Back : " << v.back() << endl;
    cout << "At : " << v.back() << endl;
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    // Printing the vector
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << ", ";
    }
    cout << endl;

    return 0;
}