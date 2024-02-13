/*
File: BitsByte.h
Author: Matthew Kusto
Decription: This is the header file
Date: 01/27/2024
*/
#ifndef BITSBYTE_H
#define BITSBYTE_H

#include <string>
using namespace std;

class BitsByte
{
public:
    /**
     * @brief Construct a new Bits Byte object
     *
     */
    BitsByte();

    /**
     * @brief Construct a new Bits Byte object
     *
     * @param val
     */
    BitsByte(int val);

    BitsByte(int *ar);

    /**
     * @brief Construct a new Bits Byte object
     *
     * @param val
     */
    BitsByte(string val);

    /**
     * @brief
     *
     * @param adding
     * @return int
     */
    int add(int adding);

    /**
     * @brief
     *
     * @param subtracting
     * @return int
     */
    int sub(int subtracting);

    /**
     * @brief
     *
     * @param multiplying
     * @return int
     */
    int mul(int multiplying);

    /**
     * @brief
     *
     * @param dividing
     * @return int
     */
    int div(int dividing);

    /**
     * @brief Set the Value object
     *
     * @param value
     */
    void setValue(int value);

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
     * @return string
     */
    string toString();

    /**
     * @brief
     *
     * @return int
     */
    int toInt();

private:
    // array that stores 8 values
    int bits[8] = {};

    /**
     * @brief
     *
     * @return int
     */
    int bitsToInt() const;
};
#endif