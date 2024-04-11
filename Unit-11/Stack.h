#ifndef STACK_H
#define STACK_H

// LIFO
#include "DoublyLinkedList.h"

template <class T>
class Stack : public DoublyLinkedList<T>
{
public:
    /**
     * @brief 
     * 
     * @param data 
     */
    void push(T data)
    {
        // Will be using addToFront function
        this->addToFront(data);
    }

    /**
     * @brief 
     * 
     * @return T 
     */
    T pop() // pops head
    {
        T item = this->getHead()->data;
        this->deleteNode(item);
        return item;
    }

    /**
     * @brief 
     * 
     * @return T 
     */
    T peek()
    {
        return this->getHead()->data;
    }
};

#endif // !STACK_H