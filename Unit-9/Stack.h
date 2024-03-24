#ifndef STACK_H
#define STACK_H

const int EMPTY = -1;
const int STACKMAX = 1000;
const int FULL = STACKMAX - 1;

template <class T>
class Stack
{
private:
    int top;
    int stackArray[STACKMAX];

public:
    /**
     * @brief Construct a new Stack object
     *
     */
    Stack() : top(EMPTY), stackArray{0} {}

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool empty()
    {
        return this->top == EMPTY ? true : false;
    }

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool full()
    {
        return this->top == FULL ? true : false;
    }

    /**
     * @brief
     *
     * @param data
     * @return true
     * @return false
     */
    bool push(T data)
    {
        if (this->full())
        {
            return false;
        }

        this->stackArray[++top] = data;
        return true;
    }

    /**
     * @brief
     *
     * @return T
     */
    T pop() // T
    {
        if (this->empty())
        {
            return EMPTY;
        }

        return this->stackArray[top--];
    }

    /**
     * @brief
     *
     * @return T
     */
    T peek()
    {
        return this->stackArray[top];
    }

    /**
     * @brief
     *
     */
    void clear()
    {
        while (top > EMPTY)
        {
            this->pop();
        }
        top = EMPTY;
    }
};

#endif // !STACK_H
