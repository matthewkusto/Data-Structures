#include "BitsWord.h"

/**
 * @brief Construct a new Bits Word:: Bits Word object
 *
 */
BitsWord::BitsWord() : BitsWord(0) {}

/**
 * @brief Construct a new Bits Word:: Bits Word object
 *
 * @param value
 */
BitsWord::BitsWord(int value) : mLower(nullptr), mUpper(nullptr)
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
    return mUpper;
};

/**
 * @brief
 *
 * @return string
 */
string BitsWord::toString()
{
    string something = mLower->toString();
    string other = mUpper->toString();
    return other.append(something);
}

/**
 * @brief
 *
 * @return int
 */
int BitsWord::toInt()
{
    int i = stoi(toString(), nullptr, 2);
    return i;
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