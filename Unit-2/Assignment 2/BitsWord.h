#include "BitsByte.h"

class BitsWord
{
private:
    BitsByte *mLower;
    BitsByte *mUpper;

public:
    /**
     * @brief Construct a new Bits Word object
     *
     */
    BitsWord();

    /**
     * @brief Construct a new Bits Word object
     *
     * @param value
     */
    BitsWord(int value);

    /**
     * @brief Destroy the Bits Word object
     *
     */
    ~BitsWord();

    /**
     * @brief Set the Value object
     *
     * @param value
     */
    void setValue(int value); // sets mUpper and mLower

    /**
     * @brief Get the Lower object
     *
     * @return BitsByte*
     */
    BitsByte *getLower();

    /**
     * @brief Get the Upper object
     *
     * @return BitsByte*
     */
    BitsByte *getUpper();

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
};
