/*
File: BitsByte.cpp
Author: Matthew Kusto
Decription: This is the source file
Date: 01/27/2024
*/

#include "BitsByte.h"

// #################################################
//  @par Name
//      BitsByte()
//  @purpose
//      Singleton that returns the instance of the class
//  @param [in] :
//      parameters are 0
//  @return
//      The instance of the class
//  @par References
//      None
//  @par Notes
//      Default constructor
// ###############################################
BitsByte::BitsByte() : BitsByte(0) {}

// #################################################
//  @par Name
//      BitsByte(int val)
//  @purpose
//      set the `val` param to the bits (binary code)
//  @param [in] :
//      an interger named val
//  @return
//      None
//  @par References
//      None
//  @par Notes
//      defualt function if an interger is entered
// ###############################################
BitsByte::BitsByte(int val)
{
    this->setValue(val);
}

// #################################################
//  @par Name
//      BitsByte(int* ar)
//  @purpose
//      Sets the data section with the value found in the array//
//  @param [in] :
//      an array that points to the memory address
//  @return
//      None
//  @par References
//      points to the array that is in this function
//  @par Notes
//      None
// ###############################################
BitsByte::BitsByte(int *ar)
{
    for (int i = 0; i < 8; i++)
    {
        bits[i] += ar[i];
    }
}

// #################################################
//  @par Name
//      BitsByte(string val)
//  @purpose
//      Sets the value of the data section to the value found in val
//  @param [in] :
//      a string named val
//  @return
//      None
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
BitsByte::BitsByte(string val)
{
    for (int i = 0; i < 8; i++)
    {
        bits[i] = val[i];
    }
}

// #################################################
//  @par Name
//      bitsToInt()
//  @purpose
//      Converts the bits from the array `bits` into an int
//  @param [in] :
//      None
//  @return
//      returns the int
//  @par References
//      const
//  @par Notes
//      None
// ###############################################
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

// #################################################
//  @par Name
//      setValue(int)
//  @purpose
//      sets the value of the bits to either 1 or 0
//  @param [in] :
//      an interger named value
//  @return
//      None, a void function
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
void BitsByte::setValue(int value)
{
    int mask = 1;
    for (int i = 0; i < 8; i++)
    {
        bits[i] = value & mask;
        value >>= 1;
    }
}

// #################################################
//  @par Name
//      bitsToInt()
//  @purpose
//      find the location of the bit in the `bits` array
//  @param [in] :
//      takes in the index number for locating the bit
//  @return
//      returns the bit location
//  @par References
//      const
//  @par Notes
//      None
// ###############################################
int BitsByte::at(int index) const
{
    return bits[index];
}

// #################################################
//  @par Name
//      toString()
//  @purpose
//      to convert the binary (1's & 0's) from the array into a string
//  @param [in] :
//      None
//  @return
//      returns the string
//  @par References
//      const
//  @par Notes
//      return array as string
// ###############################################
string BitsByte::toString() const
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

// #################################################
//  @par Name
//      toInt()
//  @purpose
//      calls the bitsToInt() function to bring back the int intitally input
//  @param [in] :
//      None
//  @return
//      returns the int
//  @par References
//      const
//  @par Notes
//      None
// ###############################################
int BitsByte::toInt() const
{
    // int i = stoi(toString(), nullptr, 2);
    return bitsToInt();
}

// #################################################
//  @par Name
//      add(int adding)
//  @purpose
//      if the user want to add to the setValue(), they can do so
//  @param [in] :
//      an int adding
//  @return
//      returns the updated number after being added (it updates the bits as well)
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
int BitsByte::add(int adding)
{
    return bitsToInt() + adding;
}

// #################################################
//  @par Name
//      sub(int subtracting)
//  @purpose
//      if the user want to subtract from the setValue(), they can do so
//  @param [in] :
//      an int subtracting
//  @return
//      returns the updated number after being subtracted (it updates the bits as well)
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
int BitsByte::sub(int subtracting)
{
    return bitsToInt() - subtracting;
}

// #################################################
//  @par Name
//      mul(int multiplying)
//  @purpose
//      if the user want to multply from the setValue(), they can do so
//  @param [in] :
//      an int multiplying
//  @return
//      returns the updated number after being multiplied (it updates the bits as well)
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
int BitsByte::mul(int multiplying)
{
    return bitsToInt() * multiplying;
}

// #################################################
//  @par Name
//      div(int dividing)
//  @purpose
//      if the user want to divide from the setValue(), they can do so
//  @param [in] :
//      an int dividing
//  @return
//      returns the updated number after being divided (it updates the bits as well)
//  @par References
//      None
//  @par Notes
//      None
// ###############################################
int BitsByte::div(int dividing)
{
    return bitsToInt() / dividing;
}