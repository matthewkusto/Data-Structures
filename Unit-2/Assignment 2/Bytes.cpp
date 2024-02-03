/*
File: BitsByte.cpp
Author: Matthew Kusto
Decription: This is the source file
Date: 01/27/2024
*/

#include "BitsByte.h"

/**
 * @brief Construct a new Bits Byte:: Bits Byte object
 *
 */
BitsByte::BitsByte() : BitsByte(0) {}

/**
 * @brief Construct a new Bits Byte:: Bits Byte object
 *
 * @param val
 */
BitsByte::BitsByte(int val)
{
    this->setValue(val);
}

/**
 * @brief Construct a new Bits Byte:: Bits Byte object
 *
 * @param ar
 */
BitsByte::BitsByte(int *ar)
{
    for (int i = 0; i < 8; i++)
    {
        bits[i] += ar[i];
    }
}

/**
 * @brief Construct a new Bits Byte:: Bits Byte object
 *
 * @param val
 */
BitsByte::BitsByte(string val)
{
    for (int i = 0; i < 8; i++)
    {
        bits[i] = val[i];
    }
}

/**
 * @brief
 *
 * @return int
 */
int BitsByte::bitsToInt() const
{
    int result = 0;
    for (int i = 7; i >= 0; i--)
    {
        result <<= 1;
        result += bits[i];
    }
    return result;
}

/**
 * @brief
 *
 * @param value
 */
void BitsByte::setValue(int value)
{
    int mask = 1;
    for (int i = 0; i < 8; i++)
    {
        bits[i] = value & mask;
        value >>= 1;
    }
}

/**
 * @brief
 *
 * @param index
 * @return int
 */
int BitsByte::at(int index) const
{
    return bits[index];
}

/**
 * @brief
 *
 * @return string
 */
string BitsByte::toString()
{
    string _bits;
    int mask = 1;
    for (int i = 7; i >= 0; i--)
    {
        if (bits[i] & (mask))
        {
            _bits += '1';
        }
        else
        {
            _bits += '0';
        }
    }
    return _bits;
}

/**
 * @brief
 *
 * @return int
 */
int BitsByte::toInt()
{
    // int i = stoi(toString(), nullptr, 2);
    return bitsToInt();
}

/**
 * @brief
 *
 * @param adding
 * @return int
 */
int BitsByte::add(int adding)
{
    return bitsToInt() + adding;
}

/**
 * @brief
 *
 * @param subtracting
 * @return int
 */
int BitsByte::sub(int subtracting)
{
    return bitsToInt() - subtracting;
}

/**
 * @brief
 *
 * @param multiplying
 * @return int
 */
int BitsByte::mul(int multiplying)
{
    return bitsToInt() * multiplying;
}

/**
 * @brief
 *
 * @param dividing
 * @return int
 */
int BitsByte::div(int dividing)
{
    return bitsToInt() / dividing;
}