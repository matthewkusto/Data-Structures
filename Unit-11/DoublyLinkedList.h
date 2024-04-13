#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *Next = NULL;
	Node *Prev = NULL;
};

template <class T>
class DoublyLinkedList
{
public:
	/**
	 * @brief Construct a new Doubly Linked List object
	 *
	 */
	DoublyLinkedList() : mHead(NULL), mTail(NULL) {}

	/**
	 * @brief
	 *
	 * @param data
	 * @note this came from the lecture
	 */
	void addToEnd(T data) // from lecture
	{

		if (mHead == NULL)
		{
			Node<T> *n = new Node<T>;
			n->Next = NULL;
			n->data = data;
			n->Prev = NULL;
			mTail = mHead = n;
		}
		else
		{
			Node<T> *p = mHead; // Start at Head

			// Traverse to the end
			while (p->Next != NULL)
			{
				p = p->Next;
			}

			// Create the new Node
			Node<T> *n = new Node<T>;
			n->Next = NULL;
			n->data = data;
			n->Prev = NULL;

			p->Next = n; // Assign the new node to the end

			n->Prev = p;
			mTail = n; // Reassign the tail to the new node added.
		}
		count++;
	}

	/**
	 * @brief
	 *
	 * @param data
	 * @note adds node to the front (Made myself)
	 */
	void addToFront(T data)
	{
		if (mHead == NULL)
		{
			Node<T> *n = new Node<T>;
			n->Next = NULL;
			n->data = data;
			n->Prev = NULL;
			mTail = mHead = n;
		}
		else
		{
			// New node
			Node<T> *p = new Node<T>;
			p->Next = NULL;
			p->data = data;
			p->Prev = NULL;

			//
			p->Next = mHead;
			mHead->Prev = p;
			mHead = p;
		}
		count++;
	}

	/**
	 * @brief
	 * @note this came from the lecture
	 */
	void printList()
	{
		Node<T> *p = mHead;
		cout << "HEAD: ";
		while (p != NULL)
		{
			cout << p->data << " <--> ";
			p = p->Next;
			if (p == NULL)
			{
				cout << "NULL :Tail" << endl;
				;
			}
		}
	}

	/**
	 * @brief
	 *
	 * @param search
	 * @param data
	 * @note this came from the lecture
	 */
	void insert(T search, T data)
	{
		Node<T> *p = mHead;
		while (p->data != search)
			p = p->Next;

		Node<T> *n = new Node<T>;
		n->data = data;

		// Watch the order in which things are done
		n->Next = p->Next;
		n->Prev = p;
		p->Next->Prev = n;
		p->Next = n;

		count++;
	}

	/**
	 * @brief
	 *
	 * @param search
	 * @note this came from the lecture
	 */
	void deleteNode(T search) // from lecture
	{
		Node<T> *p = mHead;

		if (p->data == search) // checking the head
		{
			mHead = mHead->Next; // updates the head to the next node
			delete p;
			count--;
			return;
		}

		while (p->Next->data != search)
		{
			p = p->Next;
		}

		if (p->Next->Next == NULL) // If at the end delete the end
		{
			p = mTail;
			mTail = mTail->Prev;
			mTail->Next = NULL;
			p->Prev = NULL;
			delete p;
		}
		else
		{
			Node<T> *delPtr = p->Next;
			p->Next->Next->Prev = p;
			p->Next = p->Next->Next;
			delPtr->Next = NULL;
			delPtr->Prev = NULL;
			delete delPtr;
		}
		count--;
	}

	/**
	 * @brief Get the Head object
	 *
	 * @return Node<T>*
	 * @note Made myself
	 */
	Node<T> *getHead() const
	{
		return mHead;
	}

	/**
	 * @brief
	 *
	 * @return int
	 * @note Made myself
	 */
	int length()
	{
		return count;
	}

	/**
	 * @brief
	 *
	 * @return true
	 * @return false
	 */
	bool isEmpty()
	{
		return count > 0 ? false : true;
	}

private:
	Node<T> *mHead = new Node<T>;
	Node<T> *mTail = new Node<T>;
	int count = 0;
};

#endif // !DOUBLYLINKEDLIST_H