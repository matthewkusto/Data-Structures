#include "MathWord.h"
#include "BitsWord.h"
#include <iostream>

int main()
{
    BitsWord bw;

    bw.setValue(259);

    cout << bw.getUpper()->toString() << endl;
    cout << bw.getLower()->toString() << endl;

    cout << bw.toInt() << endl;
    cout << bw.toString() << endl;

    return 0;
}