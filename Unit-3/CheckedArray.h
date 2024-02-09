/*
File: CheckedArray.h
Author: Matthew Kusto
Decription: This is the header file
Date: 02/09/2024
*/

#ifndef CHECKEDARRAY_H
#define CHECKEDARRAY_H

#include <cstdlib>
#include <string>
using namespace std;

class CheckedArray
{
private:
    int mSize = 0;       // holds size of array
    int* myArray = NULL; // array

public:
    /**
     * @brief Construct a new Checked Array object
     *
     */
    CheckedArray();

    /**
     * @brief Construct a new Checked Array object
     *
     * @param size
     */
    CheckedArray(int size);

    /**
     * @brief Destroy the Checked Array object
     *
     */
    ~CheckedArray();

    /**
     * @brief
     *
     * @param size
     * @param val
     * @return true
     * @return false
     */
    bool initilize(int size, int val = 0);

    /**
     * @brief
     *
     * @param index
     * @return int
     */
    int at(int index) const;

    /**
     * @brief
     *
     * @param index
     * @param value
     */
    void set(int index, int value);
};

#endif // !CHECKEDARRAY_H