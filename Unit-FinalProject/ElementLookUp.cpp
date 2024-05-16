#include "ElementLookUp.h"

/**
 * @brief
 *
 * @param number
 * @return string
 * @note looks for element in the avltree using the atomic number
 */
string ElementLookUp::lookUp(int number)
{
    vector<periodTable> table = node.getElements();
    for (periodTable &tab : table)
    {
        if (tab.aNumber == number)
        {
            ostringstream oss;
            oss << "Atomic Number: " << tab.aNumber << ", "
                << "Name: " << tab.name << ", "
                << "Symbol: " << tab.symbol << ", "
                << "Atomic Weight: " << tab.aWeight << endl;
            return oss.str();
        }
    }
}

/**
 * @brief
 *
 * @param name
 * @return string
 * @note looks for element in the avltree using the name
 */
string ElementLookUp::lookUp(const string &name)
{
    vector<periodTable> elem = node.getElements();
    for (periodTable &elements : elem)
    {
        if (elements.name == name)
        {
            ostringstream oss;
            oss << "Atomic Number: " << elements.aNumber << ", "
                << "Name: " << elements.name << ", "
                << "Symbol: " << elements.symbol << ", "
                << "Atomic Weight: " << elements.aWeight << endl;
            return oss.str();
        }
        else
        {
            ostringstream oss;
            oss << "Cannot find, maybe you miss spelled it?";
            return oss.str();
        }
    }
}

/**
 * @brief
 *
 * @param fileName
 * @note reads file
 */
void ElementLookUp::readFile(const string &fileName)
{
    ifstream theFilesIn(fileName);

    string line;
    while (getline(theFilesIn, line))
    {
        istringstream iss(line);

        // Parse fields from the line
        string name, symbol, varNumberStr, varWeightStr;
        getline(iss, name, ',');         // Name
        getline(iss, symbol, ',');       // Symbol
        getline(iss, varNumberStr, ','); // Atomic Number (as string)
        getline(iss, varWeightStr, ','); // Atomic Weight (as string)

        // Convert string representations to numeric types
        int aNumber = stoi(varNumberStr);
        double aWeight = stod(varWeightStr);

        // Create a periodTable object
        periodTable theElements(aNumber, aWeight, symbol, name);

        // Insert the periodTable object into the AVL tree
        node.insert(theElements);
    }

    theFilesIn.close();
}

/**
 * @brief
 *
 * @param fileName
 * @note edits file
 */
void ElementLookUp::fileEditor(const string &fileName)
{
    ifstream inFile(fileName);
    string trash;
    getline(inFile, trash);
    ofstream outFile("editedPeriodicTable.csv");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);
            string field;
            int fieldIndex = 0;
            while (getline(ss, field, ','))
            {
                if (fieldIndex <= 3)
                {
                    outFile << field;
                    if (fieldIndex < 3)
                    {
                        outFile << ",";
                    }
                    else
                    {
                        outFile << endl;
                    }
                }
                fieldIndex++;
            }
        }
    }
    inFile.close();
    outFile.close();
}