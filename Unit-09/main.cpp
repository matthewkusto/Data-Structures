#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    // Task 1 - Testing Stack Functionality
    cout << "Testing Stack Functionality..." << endl;
    cout << "==============================" << endl;

    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    for (int index = 0; index < 3; ++index)
    {
        cout << stack.pop() << endl;
    }

    stack.push(50);
    cout << stack.peek() << endl;
    stack.clear();
    cout << stack.empty() << endl;

    // Task 2 - Testing Queue Functionality
    cout << "Testing Queue Functionality..." << endl;
    cout << "==============================" << endl;

    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    for (int index = 0; index < 3; ++index)
    {
        cout << queue.peek() << endl;
        queue.dequeue();
    }

    cout << queue.isEmpty() << endl;

    // ======================================

    // Task 3 - FileIO
    ifstream inFile("PalCheck.txt", ios::in);
    Stack<char> string1; // last in, first out (LIFO)
    Queue<char> string2; // first in, first out (FIFO)

    if (inFile)
    {
        char line[1000];
        while (inFile.getline(line, 1000))
        {
            string s(line);
            for (char c : line)
            {
                c = tolower(c);
                if ((c >= 97) && (c <= 122))
                {
                    string1.push(c);
                    string2.enqueue(c);
                }
            }
            bool isPal = true;
            while (!string1.empty() && !string2.isEmpty())
            {
                if (string1.pop() != string2.dequeue())
                {
                    isPal = false;
                    break;
                }
            }
            if (isPal)
            {
                cout << "PALINDROME: " << setw(5) << s << endl;
            }
            else
            {
                cout << "Not Palindrome: " << setw(5) << s << endl;
            }
            string1.clear();
            string2.clear();
            fill(begin(line), end(line), 0);
        }
    }
    inFile.close();

    return 0;
}