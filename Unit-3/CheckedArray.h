#ifndef CHECKEDARRRAY_H
#define CHECKEDARRRAY_H

#include <cstdlib>
using namespace std;

class CheckedArray
{
private:
    int *myArray{NULL}; // array
    int mSize{};        // holds size of array

public:
    // fill the value of the array w/ 10 0's
    CheckedArray();
    // Overloaded constructor which will initialize the array to size and fill it with 0's
    CheckedArray(int size);
    ~CheckedArray();
    bool initilize(int size, int val = 0);
    int at(int index) const;
    void set(int index, int value);
};

#endif // CHECKEDARRRAY_H