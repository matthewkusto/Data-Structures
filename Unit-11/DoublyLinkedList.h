#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};

template <class T>
class DoublyLinkedList
{
public:

	DoublyLinkedList() : mHead(nullptr), mTail(nullptr) {}

	void addToEnd(T data) // from lecture
	{

		if (mHead == NULL)
		{
			Node<T>* n = new Node<T>;
			n->Next = NULL;
			n->data = data;
			n->Prev = NULL;
			mTail = mHead = n;
		}
		else
		{
			Node<T>* p = mHead; // Start at Head		

			//Traverse to the end
			while (p->Next != nullptr)
			{
				p = p->Next;
			}

			// Create the new Node
			Node<T>* n = new Node<T>;
			n->Next = NULL;
			n->data = data;
			n->Prev = NULL;

			p->Next = n;   //Assign the new node to the end 

			n->Prev = p;
			mTail = n;  // Reassign the tail to the new node added. 
		}
	}

	// adds node to the front (Made myself)
	void addToFront(T data)
	{
		if (mHead == NULL)
		{
			Node<T>* n = new Node<T>;
			n->data = data;
			n->Next = NULL;
			n->Prev = NULL;
			mTail = mHead = n;
		}
		else
		{
			// New node
			Node<T>* p = new Node<T>;
			p->Next = NULL;
			p->data = data;
			p->Prev = NULL;

			// 
			p->Next = mHead;
			mHead->Prev = p;
			mHead = p;
		}
	}

	// prints
	void printList()
	{
		Node<T>* p = mHead;
		cout << "HEAD: ";
		while (p != NULL)
		{
			cout << p->data << " <--> ";
			p = p->Next;
			if (p == NULL)
			{
				cout << "NULL :Tail" << endl;;
			}
		}
	}

	// 
	void insert(T search, T data)
	{
		Node<T>* p = mHead;
		while (p->data != search)
			p = p->Next;

		Node<T>* n = new Node<T>;
		n->data = data;


		// Watch the order in which things are done
		n->Next = p->Next;
		n->Prev = p;
		p->Next->Prev = n;
		p->Next = n;

		count++;
	}

	void deleteNode(T search) // from lecture
	{
		Node<T>* p = mHead;

		if (p->data == search) // checking the head
		{
			mHead = mHead->Next; // updates the head to the next node
			mHead->Prev = NULL; // updates the previous of the head to NULL
			p->Next = NULL;
			delete p;
			return;
		}

		while (p->Next->data != search)
		{
			p = p->Next;
		}

		if (p->Next->Next == NULL)		// If at the end delete the end
		{
			p = mTail;
			mTail = mTail->Prev;
			mTail->Next = NULL;
			p->Prev = NULL;
			delete p;
		}
		else
		{
			Node<T>* delPtr = p->Next;
			p->Next->Next->Prev = p;
			p->Next = p->Next->Next;
			delPtr->Next = NULL;
			delPtr->Prev = NULL;
			delete delPtr;
		}
	}

	// prints the doubly linked list in reverse
	void printBackward()
	{
		Node<T>* p = mTail;
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->Prev;
		}
	}

	Node<T>* getHead() const
	{
		return mHead;
	}

	Node<T>* getTail() const
	{
		return mTail;
	}
	
private:

	Node<T>* mHead = new Node<T>;
	Node<T>* mTail = new Node<T>;
	int count = 0;
};

#endif // !DOUBLYLINKEDLIST_H
