#ifndef MATHWORD_H
#define MATHWORD_H

#include "BitsWord.h"
class MathWord
{
public:
    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *add(BitsWord &num1, BitsWord &num2);

    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *sub(BitsWord &num1, BitsWord &num2);

    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *mul(BitsWord &num1, BitsWord &num2);

    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *div(BitsWord &num1, BitsWord &num2);

    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *max(BitsWord &num1, BitsWord &num2);

    /**
     * @brief
     *
     * @param num1
     * @param num2
     * @return BitsWord*
     */
    static BitsWord *min(BitsWord &num1, BitsWord &num2);
};

#endif // !MATHWORD_H