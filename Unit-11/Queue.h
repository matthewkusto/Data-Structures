#ifndef QUEUE_H
#define QUEUE_H

// FIFO
#include "DoublyLinkedList.h"

template <class T>
class Queue : public DoublyLinkedList<T>
{
public:
    /**
     * @brief 
     * 
     * @param data 
     */
    void enqueue(T data)
    {
        this->addToEnd(data);
    }

    /**
     * @brief 
     * 
     * @return T 
     */
    T dequeue() // pops head
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

#endif // !QUEUE_H