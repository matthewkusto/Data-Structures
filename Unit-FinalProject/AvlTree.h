#ifndef AVLTREE_H
#define AVLTREE_H

#define SPACE 10

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct periodTable
{
    string symbol, name;
    int aNumber;    // atomic number
    double aWeight; // atomic weight

    /**
     * @brief Construct a new period Table object
     *
     * @param aNumber
     * @param aWeight
     * @param symbol
     * @param name
     */
    periodTable(int aNumber, double aWeight, string symbol, string name)
        : aNumber(aNumber), aWeight(aWeight), symbol(symbol), name(name) {}

    /**
     * @brief
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator<(const periodTable &other) const { return aNumber < other.aNumber; }

    /**
     * @brief
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator==(const periodTable &other) const { return aNumber == other.aNumber; }
};

template <class T>
class AvlNode
{
public:
    T element;
    AvlNode *left;
    AvlNode *right;
    int height;

    // might have to initialize the count;
    /**
     * @brief Construct a new Avl Node object
     *
     * @param theElement
     * @param lt
     * @param rt
     * @param h
     */
    AvlNode(const T &theElement, AvlNode *lt, AvlNode *rt, int h = 0)
        : element(theElement), left(lt), right(rt), height(h) {}
};

template <class T>
class AvlTree
{
public:
    /**
     * @brief Construct a new Avl Tree object
     *
     */
    AvlTree() : root(NULL) {}

    /**
     * @brief Destroy the Avl Tree object
     *
     */
    ~AvlTree()
    {
        makeEmpty();
    }

    /**
     * @brief
     *
     * @return T&
     */
    T &findMin()
    {
        return elementAt(findMin(this->root));
    }

    /**
     * @brief
     *
     * @return T&
     */
    T &findMax()
    {
        return elementAt(findMax(this->root));
    }

    /**
     * @brief
     *
     * @param x
     * @return T&
     */
    T &find(const T &x)
    {
        return elementAt(find(x, this->root));
    }

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool isEmpty() const
    {
        return root == NULL; // og is root
    }

    /**
     * @brief
     *
     */
    void printTree() const
    {

        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printTree(this->root, 0);
    }

    /**
     * @brief
     *
     */
    void makeEmpty()
    {
        makeEmpty(this->root);
    }

    /**
     * @brief
     *
     * @param x
     */
    void insert(const T &x)
    {
        insert(x, this->root);
    }

    /**
     * @brief
     *
     * @param x
     */
    void remove(const T &x)
    {
        remove(x, this->root);
    }

    /**
     * @brief
     *
     * @param rhs
     * @return const AvlTree&
     */
    const AvlTree &operator=(const AvlTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    }

    /**
     * @brief Get the Root object
     *
     * @return AvlNode<T>*
     */
    AvlNode<T> *getRoot() const
    {
        return root; // root was og
    }

    AvlNode<T> *getElements() const
    {
        periodTable elements(0, 0.0, "", "");
        return elements.name;
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
        return contains(data, this->root);
    }

    /**
     * @brief Get the Elements object
     *
     * @return vector<T>
     */
    vector<T> getElements()
    {
        vector<T> elements;
        getElements(root, elements);
        return elements;
    }

private:
    AvlNode<T> *root;

    /**
     * @brief Get the Elements object
     *
     * @param tree
     * @param elements
     */
    void getElements(AvlNode<T> *tree, vector<T> &elements)
    {
        if (tree != NULL)
        {
            getElements(tree->left, elements);
            elements.push_back(tree->element);
            getElements(tree->right, elements);
        }
    }

    /**
     * @brief
     *
     * @param root
     * @return T&
     * @note from lecture
     */
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

    /**
     * @brief
     *
     * @param x
     * @param root
     * @note from lecture
     */
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

    /**
     * @brief
     *
     * @param x
     * @param root
     * @note from lecture
     */
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

    /**
     * @brief
     *
     * @param t
     * @return AvlNode<T>*
     * @note from lecture
     */
    AvlNode<T> *findMin(AvlNode<T> *t) const
    {
        if (t == NULL)
            return t;

        while (t->left != NULL)
            t = t->left;
        return t;
    }

    /**
     * @brief
     *
     * @param t
     * @return AvlNode<T>*
     * @note from lecture
     */
    AvlNode<T> *findMax(AvlNode<T> *t) const
    {
        if (t == NULL)
            return t;

        while (t->right != NULL)
            t = t->right;
        return t;
    }

    /**
     * @brief
     *
     * @param x
     * @param t
     * @return AvlNode<T>*
     * @note from lecture
     */
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

    /**
     * @brief
     *
     * @param t
     * @note from lecture
     */
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

    /**
     * @brief
     *
     * @param t
     * @note from lecture
     */
    void printTree(AvlNode<T> *t) const
    {
        if (t != NULL)
        {
            printTree(t->left);
            cout << t->element << endl;
            printTree(t->right);
        }
    }

    /**
     * @brief
     *
     * @param t
     * @param space
     */
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

    /**
     * @brief
     *
     * @param t
     * @return AvlNode<T>*
     * @note from lecture
     */
    AvlNode<T> *clone(AvlNode<T> *t) const
    {
        if (t == NULL)
            return NULL;
        else
            return new AvlNode(t->element, clone(t->left),
                               clone(t->right), t->height);
    }

    // Avl manipulations
    /**
     * @brief
     *
     * @param root
     * @return int
     * @note from lecture
     */
    int height(AvlNode<T> *root) const
    {
        return root == NULL ? -1 : root->height;
    }

    /**
     * @brief
     *
     * @param lhs
     * @param rhs
     * @return int
     * @note from lecture
     */
    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * @brief
     *
     * @param k2
     * @note from lecture
     */
    void rotateWithLeftChild(AvlNode<T> *&k2) const
    {
        AvlNode<T> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    /**
     * @brief
     *
     * @param k1
     * @note from lecture
     */
    void rotateWithRightChild(AvlNode<T> *&k1) const
    {
        AvlNode<T> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    /**
     * @brief
     *
     * @param k3
     * @note from lecture
     */
    void doubleWithLeftChild(AvlNode<T> *&k3) const
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    /**
     * @brief
     *
     * @param k1
     * @note from lecture
     */
    void doubleWithRightChild(AvlNode<T> *&k1) const
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    /**
     * @brief
     *
     * @param data
     * @param n
     * @return true
     * @return false
     */
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