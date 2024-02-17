/*
File: BitsWord.h
Author: Matthew Kusto
Decription: This is the header file
Date: 02/16/2024
*/

#ifndef BITSWORD_H
#define BITSWORD_H

#include "BitsByte.h"
#include <string>

class BitsWord
{
private:
    BitsByte *mLower = nullptr;
    BitsByte *mUpper = nullptr;

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
#endif
