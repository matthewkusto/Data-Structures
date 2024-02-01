#include "BitsByte.h"

class BitsWord
{
private:
    BitsByte *mLower;
    BitsByte *mUpper;

public:
    BitsWord();
    BitsWord(int value);
    ~BitsWord();
    // Mutator
    void setValue(int value); // sets mUpper and mLower
    // Accessors
    BitsByte *getLower();
    BitsByte *getUpper();
};

BitsWord::BitsWord(/* args */)
{
}

BitsWord::~BitsWord()
{
}
