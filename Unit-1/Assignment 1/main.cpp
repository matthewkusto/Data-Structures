/*
File: BitsByte.cpp
Author: Matthew Kusto
Decription: Unit 1/ Assignment 1 main.cpp file
Date: 01/27/2024
*/

#include "Bytes.cpp"

int main()
{
    // BitsByte bite;

    // bite.setValue(99);

    // for (int i = 0; i < 8; i++)
    //     cout << bite.at(i) << endl;

    // cout << "Int:    " << bite.toInt() << endl;
    // cout << "String: " << bite.toString() << endl;

    BitsByte bite(7);

    BitsByte b1 = bite.add(2);

    cout << "Int:    " << b1.toInt() << endl;
    cout << "String: " << b1.toString() << endl;

    return 0;
}