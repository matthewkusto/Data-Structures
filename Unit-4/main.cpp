/*
File:main.cpp
Author: Matthew Kusto
Decription: This is the main file
Date: 02/16/2024
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "BitsByte.h"
#include "BitsWord.h"
using namespace std;

/**
 * @brief 
 * 
 * @param words 
 */
void writeWords(vector<BitsWord *> words)
{
    fstream outPut;
    outPut.open("words.txt", ios::out);
    if (outPut.is_open())
    {
        for (BitsWord *i : words)
        {
            outPut << i->toInt() << ":\t" << i->toString() << endl;
        }
        outPut.close();
    }
}

/**
 * @brief 
 * 
 * @param bytes 
 */
void writeBytes(vector<BitsByte *> bytes)
{
    fstream outPut2;
    outPut2.open("bytes.txt", ios::out);
    if (outPut2.is_open())
    {
        for (BitsByte *i : bytes)
        {
            outPut2 << i->toInt() << ":\t" << i->toString() << endl;
        }
        outPut2.close();
    }
}

int main()
{
    vector<BitsByte *> vectByte;
    vector<BitsWord *> vectWord;
    fstream myFile;

    myFile.open("numbers.txt", ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            // cout << line << endl;

            int num = stoi(line);
            if (num <= 255)
            {
                BitsByte *numbers = new BitsByte(num);
                vectByte.push_back(numbers);
                writeBytes(vectByte);
            }
            else if (num > 255)
            {
                BitsWord *numbers = new BitsWord(num);
                vectWord.push_back(numbers);
                writeWords(vectWord);
            }
        }

        // cout << "=============vectByte=================" << endl;

        // for (BitsByte* i : vectByte)
        //{
        //     //cout << vectByte[i];
        //     cout << i->toInt() << ":\t" << i->toString() << endl;
        // }

        // cout << "================vectWord===============" << endl;

        // for (BitsWord* i : vectWord)
        //{
        //     //cout << vectByte[i];
        //     cout << i->toInt() << ":\t" << i->toString() << endl;
        // }

        myFile.close();
    }

    return 0;
}