#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include "AvlTree.h"
#include <cctype>
#include <fstream>
#include <sstream>

struct WordInfo
{
    string word;
    int count = 1;

    // Comparison operators
    bool operator<(const WordInfo &other) const { return word < other.word; }
    bool operator>(const WordInfo &other) const { return word > other.word; }
    bool operator==(const WordInfo &other) const { return word == other.word; }
};

class WordCount : public AvlTree<WordInfo>
{
public:
    WordCount() {}

    void readFile(const string strName)
    {
        string forWord, aLine;
        ifstream inFile(strName);
        bool metAgain = false;

        while (getline(inFile, aLine))
        {
            istringstream strm(aLine);
            while (strm >> forWord)
            {
                WordInfo w; // for each word
                w.word = someFunc(forWord);
                if (!this->contains(w)) // not in
                {
                    this->insert(w); // goes in
                }
                else
                {
                    WordInfo &existing = this->find(w);
                    existing.count++;
                }
            }
        }
        inFile.close();
    }

    void printFile() const
    {
        printFile(this->getRoot());
    }

private:
    void printFile(AvlNode<WordInfo> *n) const
    {
        if (n != NULL)
        {
            printFile(n->left);
            cout << n->element.word << " - " << n->element.count << endl;
            printFile(n->right);
        }
    }

    string someFunc(const string &aWord)
    {
        string result;
        for (char c : aWord)
        {
            c = tolower(c);
            if (ispunct(c))
            {
                continue;
            }
            else
            {
                result += c;
            }
        }
        return result;
    }
};

#endif // !WORDCOUNT_H
