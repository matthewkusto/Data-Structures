/*
File: Word.cpp
Author: Matthew Kusto
Decription: This is the source file
Date: 02/16/2024
*/

#include "BitsWord.h"

/**
 * @brief Construct a new Bits Word:: Bits Word object
 *
 */
BitsWord::BitsWord() : BitsWord(0) {}

/**
 * @brief
 *
 * @param value
 */
void BitsWord::setValue(int value)
{
    mLower->setValue(value);
    mUpper->setValue(value >> 8);
}

/**
 * @brief Construct a new Bits Word:: Bits Word object
 *
 * @param value
 */
BitsWord::BitsWord(int value)
{
    mUpper = new BitsByte();
    mUpper->setValue(value >> 8);
    mLower = new BitsByte();
    mLower->setValue(value);
}

/**
 * @brief
 *
 * @return BitsByte*
 */
BitsByte *BitsWord::getUpper()
{
    return mUpper;
};

/**
 * @brief
 *
 * @return BitsByte*
 */
BitsByte *BitsWord::getLower()
{
    return mLower;
};

/**
 * @brief
 *
 * @return string
 */
string BitsWord::toString()
{
    return mUpper->toString() + mLower->toString();
}

/**
 * @brief
 *
 * @return int
 */
int BitsWord::toInt()
{
    int var = 0;
    var |= mUpper->toInt() << 8;
    var |= mLower->toInt();
    return var;
}

/**
 * @brief Destroy the Bits Word::Bits Word object
 *
 */
BitsWord::~BitsWord()
{
    if (mLower != nullptr)
    {

        delete mLower;
    }

    if (mUpper != nullptr)
    {
        delete mUpper;
    }
}