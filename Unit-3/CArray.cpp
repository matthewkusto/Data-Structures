#include "CheckedArray.h"

CheckedArray::CheckedArray()
{
}

CheckedArray::CheckedArray(int size)
{
}

bool CheckedArray::initilize(int size, int val = 0)
{
}

int CheckedArray::at(int index) const
{
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
        delete myArray;
    }
}