#ifndef AVLTREE_H
#define AVLTREE_H

#define SPACE 10

#include <iostream>
#include <string>
using namespace std;

template <class T>
class AvlNode
{
public:
    T element;
    AvlNode *left;
    AvlNode *right;
    int height;

    // might have to initialize the count;
    AvlNode(const T &theElement, AvlNode *lt, AvlNode *rt, int h = 0)
        : element(theElement), left(lt), right(rt), height(h) {}
    template <class T>
    friend class AvlTree;
};

template <class T>
class AvlTree
{
public:
    AvlTree() : root(NULL) {}

    ~AvlTree()
    {
        makeEmpty();
    }

    T &findMin()
    {
        return elementAt(findMin(this->root));
    }

    T &findMax()
    {
        return elementAt(findMax(this->root));
    }

    T &find(const T &x)
    {
        return elementAt(find(x, this->root));
    }

    bool isEmpty() const
    {
        return root == NULL; // og is root
    }

    void printTree() const
    {

        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printTree(this->root, 0);
    }

    void makeEmpty()
    {
        makeEmpty(this->root);
    }

    void insert(const T &x)
    {
        insert(x, this->root);
    }

    void remove(const T &x)
    {
        remove(x, this->root);
    }

    const AvlTree &operator=(const AvlTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    }

    AvlNode<T> *getRoot() const
    {
        return root; // root was og
    }

    bool contains(T data)
    {
        return contains(data, this->root);
    }

private:
    AvlNode<T> *root;

    T &elementAt(AvlNode<T> *root) // get rid of
    {
        if (root == NULL)
        {
            static T default_value;
            return default_value;
        }
        else
            return root->element;
    }

    void insert(const T &x, AvlNode<T> *&root) const
    {
        if (root == NULL)
            root = new AvlNode<T>(x, NULL, NULL);
        else if (x < root->element)
        {
            insert(x, root->left);
            if (height(root->left) - height(root->right) == 2)
                if (x < root->left->element)
                    rotateWithLeftChild(root);
                else
                    doubleWithLeftChild(root);
        }
        else if (root->element < x)
        {
            insert(x, root->right);
            if (height(root->right) - height(root->left) == 2)
                if (root->right->element < x)
                    rotateWithRightChild(root);
                else
                    doubleWithRightChild(root);
        }

        if (root != NULL)
            root->height = max(height(root->left), height(root->right)) + 1;
    }

    void remove(T x, AvlNode<T> *&root)
    {
        if (root == NULL)
            return;
        // data searched is smaller go down the left sub-tree
        else if (x < root->element)
        {
            remove(x, root->left);
            if (height(root->right) - height(root->left) > 1)
            {
                if (height(root->right->right) >= height(root->right->left))
                    rotateWithRightChild(root);
                else
                    doubleWithRightChild(root);
            }
        }
        // data being searched is larger go down the right sub-tree
        else if (x > root->element)
        {
            remove(x, root->right);
            if (height(root->left) - height(root->right) > 1)
            {
                if (height(root->left->left) >= height(root->left->right))
                    rotateWithLeftChild(root);
                else
                    doubleWithLeftChild(root);
            }
        }

        else // Key is the same as the root's key. It needs to be removed
        {
            // Node with one or no children
            if (root->left == NULL || root->right == NULL)
            {
                AvlNode<T> *temp = root->left ? root->left : root->right;
                // Case no children
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // has one child
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                AvlNode<T> *temp = findMin(root->right);
                root->element = temp->element;
                remove(temp->element, root->right);
            }
            if (root != NULL)
                root->height = max(height(root->left), height(root->right)) + 1;
        }
    }

    AvlNode<T> *findMin(AvlNode<T> *t) const
    {
        if (t == NULL)
            return t;

        while (t->left != NULL)
            t = t->left;
        return t;
    }

    AvlNode<T> *findMax(AvlNode<T> *t) const
    {
        if (t == NULL)
            return t;

        while (t->right != NULL)
            t = t->right;
        return t;
    }

    AvlNode<T> *find(const T &x, AvlNode<T> *t) const
    {
        while (t != NULL)
            if (x < t->element)
                t = t->left;
            else if (t->element < x)
                t = t->right;
            else
                return t; // Match

        return NULL; // No match
    }

    void makeEmpty(AvlNode<T> *&t) const
    {
        if (t != NULL)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = NULL;
    }

    // void printTree(AvlNode<T>* t) const
    //{
    //     if (t != NULL)
    //     {
    //         printTree(t->left);
    //         cout << t->element << endl;
    //         printTree(t->right);
    //     }
    // }

    void printTree(AvlNode<T> *t, int space) const
    {
        if (t != NULL)
        {
            space += SPACE;
            printTree(t->right, space);
            cout << endl;
            for (int i = SPACE; i < space; i++)
            {
                cout << " ";
            }
            cout << t->element << endl;
            printTree(t->left, space);
        }
    }

    AvlNode<T> *clone(AvlNode<T> *t) const
    {
        if (t == NULL)
            return NULL;
        else
            return new AvlNode(t->element, clone(t->left),
                               clone(t->right), t->height);
    }

    // Avl manipulations
    int height(AvlNode<T> *root) const
    {
        return root == NULL ? -1 : root->height;
    }

    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(AvlNode<T> *&k2) const
    {
        AvlNode<T> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode<T> *&k1) const
    {
        AvlNode<T> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(AvlNode<T> *&k3) const
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(AvlNode<T> *&k1) const
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    // added this functionality to see if a word is in the tree
    bool contains(T data, AvlNode<T> *n)
    {
        if (n == NULL)
        {
            return false;
        }
        else if (data < n->element)
        {
            return contains(data, n->left);
        }
        else if (data > n->element)
        {
            return contains(data, n->right);
        }
        else
        {
            return true; // we have a match
        }
    }
};

#endif // !AVLTREE_H