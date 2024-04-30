#include "HashTable.h"

int main()
{
    HashTable ht;
    ifstream inFile("Hashdata-1.txt");

    if (inFile.is_open())
    {
        string line, name, number;
        while (getline(inFile, line))
        {
            istringstream iss(line); // a line
            // separates the line. using a delimiter as a break
            getline(iss, name, ';');
            getline(iss, number, ';');
            ht.add(name, number); // adding the names
        }
    }
    inFile.close();

    char letter, let = 'Y';
    string name;
    do
    {
        cout << "::::::::::MAIN-MENU::::::::::" << endl;
        cout << "OPTIONS: " << endl;
        cout << "A. Lookup Name" << endl;
        cout << "B. Print Table" << endl;
        cout << "Q. Quit" << endl;
        cout << "Selection: ";
        cin >> letter;

        switch (toupper(letter))
        {
        case 'A':
            while (toupper(let) != 'N')
            {
                cout << "-----------------------------" << endl;
                cout << "Enter Name: ";
                cin >> name;
                cout << "==========" << endl;
                cout << ht.lookUp(name);
                cout << "Look up another number <y/n>?: ";
                cin >> let;
            }
            break;
        case 'B':
            cout << "-----------------------------" << endl;
            ht.printTable();
            cout << "-----------------------------" << endl;
            break;
        case 'Q':
            cout << "Have a nice day" << endl;
            break;
        }

    } while (letter != 'N');

    return 0;
}