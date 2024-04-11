//#include "DoublyLinkedList.h"
#include "RPNCalc.h"
#include "Queue.h"

int main()
{
    cout << "=== TEST CASE #1 (LIST) ===" << endl;
    DoublyLinkedList<string> lst;
    // Adding to the list
    lst.addToEnd("A");
    lst.addToEnd("B");
    lst.addToEnd("C");
    lst.addToEnd("D");
    lst.addToEnd("E");
    lst.addToFront("1");
    lst.printList();
    cout << "------" << endl;
    // deleting form the list
    lst.deleteNode("C");
    lst.printList();
    cout << "------" << endl;
    // inserting
    lst.insert("B", "O");
    lst.insert("1", "2");
    lst.printList();
    cout << "------" << endl;
    cout << "====================" << endl << endl;

    cout << "=== TEST CASE #2 (STACK: LIFO) ===" << endl;
    // LIFO
    Stack<string> stack;

    // Add to the list
    stack.push("A");
    stack.push("B");
    stack.push("C");
    stack.push("D");
    stack.push("E");
    stack.push("F");
    stack.push("G");
    stack.printList();
    cout << "------" << endl;
    stack.pop();
    stack.printList();
    cout << "------" << endl;
    cout << "Peek: " << stack.peek() << endl;
    cout << "====================" << endl << endl;

    cout << "=== TEST CASE #3 (QUEUE: FIFO) ===" << endl;
    // FIFO
    Queue<string> queue;
    queue.enqueue("1");
    queue.enqueue("2");
    queue.enqueue("3");
    queue.enqueue("4");
    queue.enqueue("5");
    queue.enqueue("6");
    queue.enqueue("7");
    queue.printList();
    cout << "------" << endl;
    queue.dequeue();
    queue.printList();
    cout << "------" << endl;
    cout << "Peek: " << queue.peek() << endl;;
    cout << "====================" << endl << endl;

    cout << "=== TEST CASE #4 (RPNCalc) ===" << endl;
    RPNCalc<string> calc;
    calc.push("3");
    calc.push("4");
    calc.performOp("+");


    return 0;

}