#ifndef ELEMENTLOOKUP_H
#define ELEMENTLOOKUP_H

#include "AvlTree.h"

class ElementLookUp
{
public:
    /**
     * @brief 
     * 
     * @param name 
     * @return string 
     */
	string lookUp(const string &name);

    /**
     * @brief 
     * 
     * @param number 
     * @return string 
     */
	string lookUp(int number);

    /**
     * @brief 
     * 
     * @param fileName 
     */
	void readFile(const string &fileName);
    
    /**
     * @brief 
     * 
     * @param fileName 
     */
	void fileEditor(const string& fileName);
private:
	AvlTree<periodTable> node;
};

#endif // ELEMENTLOOKUP_H
