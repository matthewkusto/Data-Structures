#ifndef QUEUE_H
#define QUEUE_H

const int MAXQUEUE = 1000;
const int QFULL = MAXQUEUE;
const int QEMPTY = 0;
const int EMPTYQ = -1;

template <class T>
class Queue
{
public:
    /**
     * @brief Construct a new Queue object
     *
     */
    Queue() : head(QEMPTY), tail(QEMPTY) {}

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        return this->head == this->tail;
    }

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isFull()
    {
        return this->tail == MAXQUEUE;
    }

    /**
     * @brief
     *
     * @param item
     * @return true
     * @return false
     */
    bool enqueue(T item)
    {
        if (this->isFull())
        {
            return false;
        }

        this->items[this->tail] = item;
        tail = (tail + 1) % MAXQUEUE;
        return true;
    }

    /**
     * @brief
     *
     * @return T
     */
    T dequeue()
    {
        if (this->isEmpty())
        {
            return EMPTYQ;
        }

        int item = this->items[head];
        this->head = (this->head + 1) % MAXQUEUE;
        return item;
    }

    /**
     * @brief
     *
     * @return T
     */
    T peek()
    {
        return this->items[this->head];
    }

    /**
     * @brief
     *
     */
    void clear()
    {
        while (!this->isEmpty())
        {
            this->dequeue();
        }
        head = QEMPTY;
        tail = QEMPTY;
    }

private:
    int items[MAXQUEUE];
    int head;
    int tail;
};

#endif // !QUEUE_H
