/*
File: main.cpp
Author: Matthew Kusto
Decription: This is the main file
Date: 02/09/2024
*/
#include "CheckedArray.h"
#include "BitsByte.h"
#include <iostream>

using namespace std;

int main()
{
	CheckedArray ca;
	ca.set(0, 12);
	cout << ca.at(0) << endl;

	cout << "--------------------------------------------" << endl;

	int var[8] = { 1, 1, 0, 0, 0, 1, 1, 0 };
	string val1 = "11000110";
	BitsByte b(val1), b2(var), bite;

	bite.setValue(99);

	for (int i = 0; i < 8; i++)
		cout << b.at(i) << endl;

	cout << "Int:    " << b.toInt() << endl;
	cout << "String: " << b.toString() << endl;

	cout << "--------------------------------------------" << endl;

	for (int i = 0; i < 8; i++)
		cout << b2.at(i) << endl;

	cout << "Int:    " << b2.toInt() << endl;
	cout << "String: " << b2.toString() << endl;

	cout << "--------------------------------------------" << endl;

	for (int i = 0; i < 8; i++)
		cout << bite.at(i) << endl;

	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	return 0;

}