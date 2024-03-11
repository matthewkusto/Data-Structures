#ifndef PAIRLIST_H
#define PAIRLIST_H

#include "Pair.h"
#include <vector>

template <class T>
class PairList : public vector<Pair<T>>
{
public:
    /**
     * @brief
     *
     * @param first
     * @param second
     */
    void addPair(T first, T second)
    {
        this->push_back(Pair<T>(first, second));
    }

    /**
     * @brief Get the First object
     *
     * @param second
     * @return T
     */
    T getFirst(T second)
    {
        for (int i = 0; i < this->size(); i++)
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
     * @return T
     */
    T getSecond(T first)
    {
        for (int i = 0; i < this->size(); i++)
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
    void deletePair(T first, T second)
    {
        for (int i = 0; i < this->size(); i++)
        {
            if (this->at(i).getFirst() == first && this->at(i).getSecond() == second)
            {
                this->erase(this->begin() + i);
                i--;
            }
        }
    }

    /**
     * @brief
     *
     */
    void printList()
    {
        for (int i = 0; i < this->size(); i++)
        {
            cout << this->at(i).getFirst() << " " << this->at(i).getSecond() << endl;
        }
    }
};

#endif // !PAIRLIST_H
