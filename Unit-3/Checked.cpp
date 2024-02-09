/*
File: Checked.cpp
Author: Matthew Kusto
Decription: This is the source file
Date: 02/09/2024
*/

#include "CheckedArray.h"

/**
 * @brief Construct a new Checked Array:: Checked Array object
 *
 */
CheckedArray::CheckedArray() : CheckedArray(10)
{
}

/**
 * @brief Construct a new Checked Array:: Checked Array object
 *
 * @param size
 */
CheckedArray::CheckedArray(int size)
{
    this->initilize(size);
}

/**
 * @brief
 *
 * @param size
 * @param val
 * @return true
 * @return false
 */
bool CheckedArray::initilize(int size, int val)
{
    if (this->myArray != NULL)
    {
        delete[] this->myArray;
    }

    this->myArray = new int[size]; // mSize is set to size of the array

    if (this->myArray == NULL)
    {
        return false;
    }

    this->mSize = size;

    for (int i = 0; i < size; i++)
    {
        this->myArray[i] = val;
    }

    return true;
}

/**
 * @brief
 *
 * @param index
 * @return int
 */
int CheckedArray::at(int index) const
{
    if (index >= 0 && index < this->mSize)
    {
        return this->myArray[index];
    }
    else
    {
        return -1;
    }
}

/**
 * @brief
 *
 * @param index
 * @param value
 */
void CheckedArray::set(int index, int value)
{
    if (index >= 0 && index < this->mSize && this->myArray != NULL) // checks to see if index is out of bounds
    {
        this->myArray[index] = value;
    }
    return;
}

/**
 * @brief Destroy the Checked Array:: Checked Array object
 *
 */
CheckedArray::~CheckedArray()
{
    if (this->myArray == NULL)
    {
        return;
    }
    else
    {
        delete[] this->myArray;
    }
}