/*
File: PairList.h
Author: Matthew Kusto
Decription: This is the header file
Date: 04/30/2024
*/

#ifndef PAIRLIST_H
#define PAIRLIST_H

#include "LinkedList.h"
#include "Pair.h"
#include <string>

template <class F, class S>
class PairList : public LinkedList<Pair<F, S>>
{
public:
    /**
     * @brief
     *
     * @param first
     * @param second
     */
    void addPair(F first, S second)
    {
        this->addToEnd(Pair<F, S>(first, second));
    }

    /**
     * @brief Get the First object
     *
     * @param second
     * @return F
     */
    F getFirst(S second)
    {
        for (int i = 0; i < this->count(); i++)
        {
            if (this->at(i).getSecond() == second)
            {
                return this->at(i).getFirst();
            }
        }
    }

    /**
     * @brief Get the Second object
     *
     * @param first
     * @return S
     */
    S getSecond(F first)
    {
        for (int i = 0; i < this->count(); i++)
        {
            if (this->at(i).getFirst() == first)
            {
                return this->at(i).getSecond();
            }
        }
    }

    /**
     * @brief
     *
     * @param first
     * @param second
     */
    void deletePair(F first, S second)
    {
        Pair<F, S> pair(first, second);
        this->deleteNode(pair);
    }

    /**
     * @brief
     *
     */
    void printList()
    {
        for (int i = 0; i < this->count(); i++)
        {
            cout << this->at(i).getFirst() << " " << this->at(i).getSecond() << endl;
        }
    }
};

#endif // !PAIRLIST_H
