#include <iostream>
using namespace std;

int main()
{
    int val = 99, mask = 1;
    for (int i = 0; i < 8; i++)
    {
        if (val & mask)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        mask <<= 1;
    }

    return 0;
}