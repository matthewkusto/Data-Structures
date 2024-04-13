// #include "DoublyLinkedList.h"
#include "Infix.h"
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
     cout << "====================" << endl
          << endl;

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
     cout << "====================" << endl
          << endl;

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
     cout << "Peek: " << queue.peek() << endl;
     ;
     cout << "====================" << endl
          << endl;

     cout << "=== TEST CASE #4 (RPNCalc) ===" << endl;
     RPNCalc calc;
     cout << "Test Result 1 = " << calc.performOp("1.69 2.2 +") << endl;
     cout << "Test Result 2 = " << calc.performOp("8 2.2 -") << endl;
     cout << "Test Result 3 = " << calc.performOp("4 7.6 *") << endl;
     cout << "Test Result 4 = " << calc.performOp("8 0 /") << endl;
     cout << "Test Result 5 = " << calc.performOp("3     2  5      * +") << endl;
     cout << "====================" << endl
          << endl;

     cout << "=== TEST CASE #5 (INFIX) ===" << endl;
     Infix ifx;
     string str = ifx.infixToPostfix("1*(2+3*4)+5");
     cout << "Test input 1: 1*(2+3*4)+5" << endl;
     cout << "Postfix: " << str << endl;
     cout << "Infix result: " << calc.performOp(str) << endl;
     cout << "-----" << endl;
     string str2 = ifx.infixToPostfix("30 + ( 2.2 * 4 )");
     cout << "Test input 2: 30 + (2.2 * 4)" << endl;
     cout << "Postfix: " << str2 << endl;
     cout << "Infix result: " << calc.performOp(str2) << endl;
     cout << "====================" << endl
          << endl;

     return 0;
}