#include "CheckedArray.h"

CheckedArray::CheckedArray()
{
    myArray = new int[10];
    for (int i = 0; i < sizeof(myArray); i++)
    {
        myArray[i] = 0;
    }
}

CheckedArray::CheckedArray(int size)
{
    myArray = new int[size]; // allocating new memory since it is an array with pointer
    for (int i = 0; i < sizeof(myArray); i++)
    {
        myArray[i] = 0;
    }
}

bool CheckedArray::initilize(int size, int val = 0)
{
    if (myArray != NULL)
    {
        delete[] myArray;
        myArray = NULL;
    }
    
    myArray = new int[size]; // mSize is set to size of the array
    
    return true;

}

int CheckedArray::at(int index) const
{
    return myArray[index];
}

void CheckedArray::set(int index, int value)
{
}

CheckedArray::~CheckedArray()
{
    if (myArray == nullptr)
    {
        return;
    }
    else
    {
        delete[] myArray;
    }
}