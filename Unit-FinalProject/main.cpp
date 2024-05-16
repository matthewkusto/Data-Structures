#include "ElementLookUp.h"

int main()
{
    ElementLookUp elu;
    elu.fileEditor("periodicTable.csv");
    elu.readFile("editedPeriodicTable.csv");
    string name;
    int number;
    char choice, option = 'y';
    while (option == 'y')
    {
        cout << "Periodic Table Menu" << endl;
        cout << "  1. Number" << endl;
        cout << "  2. Name" << endl;
        cout << "  3. Exit" << endl;
        cout << "Enter Selection: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "[goes up to 100]" << endl;
            cout << "Enter Element Number: ";
            cin >> number;
            cout << elu.lookUp(number) << endl;
            break;
        case '2':
            cout << "Enter Element Name: ";
            cin >> name;
            cout << elu.lookUp(name) << endl;
            break;
        case '3':
            cout << "Goodbye" << endl;
            option = 'n';
            break;
        default:
            cout << "Goodbye" << endl;
            option = 'n';
            break;
        }
    }

    return 0;
}