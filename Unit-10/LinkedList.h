/*
File: LinkedList.h
Author: Matthew Kusto
Decription: This is the header file
Date: 03/28/2024
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using std::cout;
using std::endl;

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
    LinkedList() : Head(nullptr) {}

    /**
     * @brief
     *
     * @param data
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

private:
    Node<T> *Head = new Node<T>;
};

#endif // !LINKEDLIST_H
