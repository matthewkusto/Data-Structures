#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T Data;
    Node *left;
    Node *right;
};

template <class T>
class BinaryTree
{
public:
    /**
     * @brief Construct a new Binary Tree object
     *
     */
    BinaryTree()
    {
        this->Root = NULL;
    }

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        return this->Root == NULL;
    }

    /**
     * @brief
     *
     * @return int
     */
    int findMin()
    {
        return this->findMin(this->Root);
    }

    /**
     * @brief
     *
     * @return int
     */
    int findMax()
    {
        return this->findMax(this->Root);
    }

    /**
     * @brief
     *
     * @param data
     */
    void insert(T data)
    {
        this->insert(data, this->Root);
    }

    /**
     * @brief
     *
     * @param data
     */
    void remove(T data)
    {
        this->remove(data, this->Root);
    }

    /**
     * @brief
     *
     * @param data
     * @return true
     * @return false
     */
    bool contains(T data)
    {
        return this->contains(data, this->Root);
    }

    /**
     * @brief
     *
     */
    void printTree()
    {
        this->printTree(this->Root);
    }

private:
    /**
     * @brief
     *
     * @param data
     * @param n
     */
    void insert(T data, Node<T> *&n) // Node is being passed by reference
    {
        // With the (*& n), new instance is created everything -> n will always be NULL. Pass by ref to ensure we are working on the Root Node
        if (n == NULL) // creats new node is n is null
        {
            n = new Node<T>;
            n->Data = data;
            n->left = NULL;
            n->right = NULL;
        }
        else if (data < n->Data) // inserts on left side of tree
        {
            insert(data, n->left); // recursion
        }
        else if (data > n->Data) // inserts on right side of tree
        {
            insert(data, n->right); // recursion
        }

        return;
    }

    /**
     * @brief
     *
     * @param data
     * @param n
     */
    void remove(T data, Node<T> *&n)
    {
        if (Root == NULL)
        {
            return; // empty tree do nothing
        }
        if (data < n->Data)
        {
            this->remove(data, n->left);
        }
        else if (data > n->Data)
        {
            this->remove(data, n->right);
        }
        else if (n->left != NULL && n->right != NULL)
        {
            n->Data = findMin(n->right);
            remove(n->Data, n->right);
        }
        else
        {
            Node<T> *oldNode = n;
            n = (n->left != NULL) ? n->left : n->right;
            delete oldNode;
        }
    }

    /**
     * @brief
     *
     * @param root
     * @return T
     */
    T findMin(Node<T> *root)
    {
        if (root->left == NULL)
        {
            return root->Data;
        }
        else
        {
            return findMin(root->left);
        }
    }

    /**
     * @brief
     *
     * @param root
     * @return T
     */
    T findMax(Node<T> *root)
    {
        if (root->right == NULL)
        {
            return root->Data;
        }
        else
        {
            return findMax(root->right);
        }
    }

    /**
     * @brief
     *
     * @param data
     * @param n
     * @return true
     * @return false
     */
    bool contains(T data, Node<T> *n)
    {
        if (n == NULL)
        {
            return false;
        }
        else if (data < n->Data)
        {
            return contains(data, n->left);
        }
        else if (data > n->Data)
        {
            return contains(data, n->right);
        }
        else
        {
            return true; // we have a match
        }
    }

    /**
     * @brief
     *
     * @param n
     */
    void printTree(Node<T> *n)
    {
        if (n != NULL)
        {
            cout << n->Data << endl;
            this->printTree(n->left);
            this->printTree(n->right);
        }
    }

    Node<T> *Root = new Node<T>; // this is the root
};

#endif // !BINARYTREE_H
