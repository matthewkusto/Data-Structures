/*
File: LinkedList.h
Author: Matthew Kusto
Decription: This is the header file
Date: 04/30/2024
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

/**
 * @brief
 *
 * @tparam T
 * @note came from lecture materials
 */
template <typename T>
struct Node
{
    // Data Section
    T Data;

    // Link Section
    Node *Next;
};

template <class T>
class LinkedList
{
public:
    /**
     * @brief Construct a new Linked List object
     *
     */
    LinkedList() : Head(NULL) {}

    /**
     * @brief
     *
     * @param data
     * @note came from lecture materials
     */
    void addToEnd(T data)
    {
        if (Head == NULL)
        {
            Head = new Node<T>;
            Head->Data = data;
            Head->Next = NULL;
        }
        else
        {
            // Set p equal to the head
            Node<T> *p = this->Head;

            // Traverse to the end of the list
            while (p->Next != NULL)
                p = p->Next;

            // Create the new node
            Node<T> *n = new Node<T>;
            n->Data = data;
            n->Next = NULL;

            // Assign the next reference to the new node
            p->Next = n;
        }
    }

    /**
     * @brief
     *
     * @param search
     * @param data
     * @note came from lecture materials
     */
    void insert(T search, T data)
    {
        Node<T> *p = Head;
        while (p->Data != search)
        {
            p = p->Next;
        }

        Node<T> *n = new Node<T>;
        n->Data = data;

        n->Next = p->Next;
        p->Next = n;
    }

    /**
     * @brief
     *
     * @param search
     * @note came from lecture materials
     */
    void deleteNode(T search)
    {
        if (Head == NULL)
            return;
        if (Head->Data == search)
        {
            Head = Head->Next;
            return;
        }
        Node<T> *p = Head;
        while (p->Next->Data != search)
        {
            p = p->Next;
        }

        Node<T> *delPtr = p->Next;
        p->Next = p->Next->Next;

        delete delPtr;
    }

    /**
     * @brief
     *
     */
    void printList()
    {
        Node<T> *p = Head;
        while (p != NULL)
        {
            cout << p->Data << endl;
            p = p->Next;
        }
    }

    /**
     * @brief
     *
     * @param search
     * @return true
     * @return false
     * @note came from lecture materials
     */
    bool contains(T search)
    {
        Node<T> *p = Head;
        while (p != NULL)
        {
            if (p->Data == search)
            {
                return true;
            }
            p = p->Next;
        }
        return false;
    }

    /**
     * @brief
     *
     * @param index
     * @return T
     * @note came from lecture materials
     */
    T at(int index)
    {
        Node<T> *p = Head;
        int i = 0;
        while (p != NULL && i != index)
        {
            p = p->Next;
            i++;
        }
        if (p == NULL)
        {
            return T();
        }
        return p->Data;
    }

    /**
     * @brief
     *
     * @return int
     * @note came from lecture materials
     */
    int count()
    {
        int count = 0;
        Node<T> *p = Head;
        while (p != NULL)
        {
            count++;
            p = p->Next;
        }
        return count;
    }

    /**
     * @brief Get the Head object
     *
     * @return Node<T>*
     */
    Node<T> *getHead()
    {
        return Head;
    }

private:
    Node<T> *Head = new Node<T>;
};

#endif // !LINKEDLIST_H
