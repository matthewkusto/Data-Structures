#include <iostream>
#include <vector>
#include <fstream>
#include "BitsByte.h"
#include "BitsWord.h"
using namespace std;

int main()
{
    vector<BitsByte *> vectByte;
    vector<BitsWord *> vectWord;
    fstream myFile;

    myFile.open("numbers(2).txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        /* code */
    }

    return 0;
}