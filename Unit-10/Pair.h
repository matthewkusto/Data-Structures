/*
File: Pair.h
Author: Matthew Kusto
Decription: This is the header file
Date: 03/28/2024
*/

#ifndef PAIR_H
#define PAIR_H

#include <cstdlib>
#include <algorithm>
using namespace std;

template <class F, class S>
class Pair
{
public:
    /**
     * @brief Construct a new Pair object
     *
     */
    Pair() : first(), second() {}

    /**
     * @brief Construct a new Pair object
     *
     * @param f
     * @param s
     */
    Pair(F f, S s) : first(f), second(s) {}

    /**
     * @brief Get the First object
     *
     * @return F
     */
    F getFirst() const
    {
        return first;
    }

    /**
     * @brief Get the Second object
     *
     * @return S
     */
    S getSecond() const
    {
        return second;
    }

    /**
     * @brief Set the First object
     *
     * @param f
     */
    void setFirst(F f)
    {
        this->first = f;
    }

    /**
     * @brief Set the Second object
     *
     * @param s
     */
    void setSecond(S s)
    {
        this->second = s;
    }

    /**
     * @brief
     *
     * @param mPair
     * @return true
     * @return false
     */
    bool operator==(Pair<F, S> &mPair) const
    {
        return (this->first == mPair.first && this->second == mPair.second);
    }

    /**
     * @brief
     *
     * @param mPair
     * @return true
     * @return false
     */
    bool operator!=(Pair<F, S> &mPair)
    {
        return !(*this == mPair); // utlizing the operator==
    }

private:
    F first;
    S second;
};

#endif // !PAIR_H
