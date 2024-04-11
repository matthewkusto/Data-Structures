#ifndef STACK_H
#define STACK_H

// LIFO
#include "DoublyLinkedList.h"

template <class T>
class Stack : public DoublyLinkedList<T>
{
public:
    void push(T data)
    {
        // Will be using addToFront function
        this->addToFront(data);
    }

    T pop() // pops head
    {
        T item = this->getHead()->data;
        this->deleteNode(item);
        return item;
    }

    T peek()
    {
        return this->getHead()->data;
    }
};

#endif // !STACK_H
