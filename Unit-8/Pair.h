#ifndef PAIR_H
#define PAIR_H

#include <cstdlib>
#include <algorithm>
using namespace std;

template <class T>
class Pair
{
public:
    /**
     * @brief Construct a new Pair object
     *
     */
    Pair() : first(NULL), second(NULL) {}

    /**
     * @brief Construct a new Pair object
     *
     * @param f
     * @param s
     */
    Pair(T f, T s) : first(f), second(s) {}

    /**
     * @brief Get the First object
     *
     * @return T
     */
    T getFirst() const
    {
        return first;
    }

    /**
     * @brief Get the Second object
     *
     * @return T
     */
    T getSecond() const
    {
        return second;
    }

    /**
     * @brief Set the First object
     *
     * @param f
     */
    void setFirst(T f)
    {
        this->first = f;
    }

    /**
     * @brief Set the Second object
     *
     * @param s
     */
    void setSecond(T s)
    {
        this->second = s;
    }

private:
    T first;
    T second;
};

#endif // !PAIR_H
