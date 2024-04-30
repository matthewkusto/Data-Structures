#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "PairList.h"
#include <sstream>
#include <fstream>
using namespace std;

const int TABLESIZE = 53;

class HashTable
{
public:
    /**
     * @brief Construct a new Hash Table object
     *
     */
    HashTable() : hashTable(TABLESIZE) {}

    /**
     * @brief
     *
     * @param name
     * @param number
     */
    void add(string name, string number)
    {
        int key = djbHash(name, TABLESIZE);   // using name and TABLESIZE to create a hash key
        hashTable[key].addPair(name, number); // key and number are added
    }

    /**
     * @brief
     *
     */
    void printTable()
    {
        for (int i = 0; i < TABLESIZE; i++)
        {
            p = hashTable[i].getHead();
            while (p != NULL)
            {
                cout << lookUp(p->Data.getFirst());
                p = p->Next;
            }
        }
    }

    /**
     * @brief
     *
     * @param name
     * @return string
     */
    string lookUp(string name)
    {
        int offset = 0;
        unsigned int theKey = djbHash(name, TABLESIZE);
        p = hashTable[theKey].getHead();
        while (p != NULL) // while p is not null
        {
            if (p->Data.getFirst() == name) // checking for data
            {
                ostringstream out;
                out << name << " " << "(" << theKey << " - " << offset << ")" << p->Data.getSecond() << endl;
                return out.str();
            }
            offset++;
            p = p->Next;
        }
    }

private:
    vector<PairList<string, string>> hashTable; // a vector that is a PairList type
    Node<Pair<string, string>> *p = new Node<Pair<string, string>>;

    /**
     * @brief
     *
     * @param str
     * @param tableSize
     * @return unsigned int
     * @note came from lecture material
     */
    unsigned int djbHash(string str, unsigned int tableSize)
    {
        int hashVal = 5381;
        string::iterator ch;
        for (ch = str.begin(); ch < str.end(); ch++)
        {
            hashVal = ((hashVal << 5) + hashVal) + static_cast<int>(*ch);
        }
        return hashVal % tableSize;
    }
};

#endif // !HASHTABLE_H
