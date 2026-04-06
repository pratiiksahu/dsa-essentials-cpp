#pragma once

template <typename T>
class Vector {
private:
    T* arr;
    int currSize;
    int maxSize;

public:
    Vector(int maxSize = 1) {
        currSize = 0;
        this->maxSize = maxSize;
        arr = new T[maxSize];
    }

    void pushback(T data) {
        if (currSize == maxSize) {
            T* oldArr = arr;          // save old pointer
            maxSize = maxSize * 2;    // double capacity
            arr = new T[maxSize];     // new heap allocation
            for (int i = 0; i < currSize; i++)
                arr[i] = oldArr[i];   // copy elements over
            delete[] oldArr;          // free old memory
        }
        arr[currSize] = data;          // insert (both cases end here)
        currSize++;
    }

    void popback() {
        if (currSize > 0) currSize--;
    }

    T front()            const { return arr[0]; }
    T back()             const { return arr[currSize - 1]; }
    T at(const int i)    const { return arr[i]; }
    T operator[](const int i) const { return arr[i]; }
    int size()             const { return currSize; }
    int capacity()         const { return maxSize; }
    bool isEmpty()         const { return currSize == 0; }
};
