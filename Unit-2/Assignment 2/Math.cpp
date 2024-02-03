#include "MathWord.h"

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::add(BitsWord &num1, BitsWord &num2)
{
    BitsWord *sum = new BitsWord(num1.toInt() + num2.toInt());

    return sum;
}

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::sub(BitsWord &num1, BitsWord &num2)
{
    BitsWord *sum = new BitsWord(num1.toInt() - num2.toInt());

    return sum;
}

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::mul(BitsWord &num1, BitsWord &num2)
{
    BitsWord *sum = new BitsWord(num1.toInt() * num2.toInt());

    return sum;
}

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::div(BitsWord &num1, BitsWord &num2)
{
    BitsWord *sum = new BitsWord(num1.toInt() / num2.toInt());

    return sum;
}

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::max(BitsWord &num1, BitsWord &num2)
{
    BitsWord *max = new BitsWord();
    if (num1.toInt() > num2.toInt())
    {
        max->setValue(num1.toInt());
    }
    else
    {
        max->setValue(num2.toInt());
    }
    return max;
}

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return BitsWord*
 */
BitsWord *MathWord::min(BitsWord &num1, BitsWord &num2)
{
    BitsWord *min = new BitsWord();
    if (num1.toInt() < num2.toInt())
    {
        min->setValue(num1.toInt());
    }
    else
    {
        min->setValue(num2.toInt());
    }
    return min;
}