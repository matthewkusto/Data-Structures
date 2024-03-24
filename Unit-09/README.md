# Project 8 Stacks / Queues

In this assignment you are going to be asked to test your understanding of generic types and how to implement them. This is an important topic  to learn because we are heading into the heavy data structures
material and are going to be using the generic type for almost all data structures that we create. This assignment is also going to test your skill with the "isa" relationship also known as inheritance. 

Note: This is a reminder that this is a Data Structures course.  This means that you are to write your own code unless otherwise specified in the assignment. The use of built in data structures types like linked lists, stacks, queues, trees, maps, graphs etc. is prohibited and will result in a 60% reduction in your grade. Furthermore, the lecture material presents code that should be used to get you started. Any data structure that is not derived from what is shown in the lecture material will not be accepted. You will receive a grade of 0 for submitting it. 

## Task  1 - The Stack Class
In the lecture for this unit you saw how to create a Stack using an array that held int type items. For this task you are to use the code shown in this unit to create a generic Stack. By making it generic it should be able to hold any data type. In C++ we call this a template. In Java a generic.

C++ -  You should use a primitive array and not a vector. You  should  also note that a template class should have all of it's code in a header file. Separating the code into .h / .cpp will create problems for you. 

Java - remember that you cannot create a generic array of primitive types so you will have to use an ArrayList instead. Since you have to use an ArrayList you should treat is as if it were an Array. Meaning, it should have a fixed size. 

Stack functionality

Constructor

Stack() - Initializes the Stack. 

Public functions

bool push(T data)  - pushes data of type T onto the stack

T pop() - Pops the value at the top of the stack and returns it

T peek() - Returns the value a the top of the stack without removing it

void clear() - Sets the Stack to an empty state

bool empty() - returns true if the Stack is empty, false otherwise.

bool full() - Returns true if the Stack is full, false otherwise.

Java - Of course the return type would be boolean not bool 

 

## Task 2 The Queue Class
In the lecture for this unit you saw how to create a Queue using an array that held int type items. For this task you are to use the code shown in this unit to create a generic Queue. By making it generic it should be able to hold any data type. In C++ we call this a template. In Java a generic.

C++ -  You should use a primitive array and not a vector. You  should  also note that a template class should have all of it's code in a header file. Separating the code into .h / .cpp will create problems for you. 

Java - remember that you cannot create a generic array of primitive types so you will have to use an ArrayList instead. Since you have to use an ArrayList you should treat is as if it were an Array. Meaning, it should have a fixed size. 

Queue functionality

Constructor

Queue() - Initializes the Queue.

Public Functions

boolean enqueue(T item) - Add an item to the end of the queue

T dequeue() - Removes a value from the front to the queue and returns it. 

T peek() - Returns the value that  the front of the queue without removing it. 

boolean isEmpty() - Returns true if the queue is empty and false otherwise. 

boolean isFull() - Returns true if the queue is full and false otherwise. 

void clear() - Clears the queue and initializes it's variables. 

C++ - Of course, the return type should be bool not boolean 

## Task  3 - Using The Stack And Queue
This is a link to a file called palCheck that contains a list of phrases.Links to an external site. Some of these phrases are palindromes. A palindrome is a word or phrase that is spelled the same way forward as it is backward. A simple example would be hannah. Of course, many of the phrases are  much more complicated.

Using the stack and the queue you are to determine which phrase is a palindrome and which is not. The strategy here is the you would do the following

In main create an instance of a Stack and a Queue.

Read a line from the file

Save the line to another variable to preserve it

In a loop push and enqueue each character. You will only need to store off the characters and not punctuation or space characters. In other words only character a-z and A-Z. You should also convert each character to either upper or lower case. This will make things easier for comparison.

Once you have all characters of the line in the Queue and Stack use a loop to dequeue and pop a character. 

Compare each character to each other. You should keep comparing as long as the characters are the same and the Stack and Queue are not empty. 

If you get through all of the characters in the Stack and Queue and all characters match you have a palindrome. Print it to the screen as PALINDROME: followed by the phrase

If you get to a point where characters do not match then you do not have a palindrome.  Print to the screen that it is not a palindrome:

Not Palindrome: followed by the phrase. 

You should loop until all of the phrases in the file have been read and checked. 

Your output should look like the following: