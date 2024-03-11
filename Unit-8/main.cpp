#include <iostream>
#include <cstdlib>
#include "PairList.h"
using namespace std;



int main()
{
	cout << ":::: TEST 1 [INTS] ::::" << endl;
	Pair<int> pair1;
	pair1.setFirst(7);
	pair1.setSecond(17);
	cout << pair1.getFirst() << " " << pair1.getSecond() << endl;
	cout << "--------" << endl;
	Pair<int> pair2(5, 10);
	cout << pair2.getFirst() << " " << pair2.getSecond() << endl;

	cout << "--------" << endl;
	PairList<int> pairlist;
	pairlist.addPair(1, 2);
	pairlist.addPair(3, 4);
	pairlist.addPair(5, 6);
	pairlist.addPair(7, 8);
	pairlist.addPair(9, 10);
	pairlist.addPair(11, 12);
	pairlist.printList();

	cout << "--------" << endl;
	cout << "Deleted Pair [3,4]" << endl;
	pairlist.deletePair(3, 4);
	pairlist.printList();
	
	cout << "--------" << endl;
	cout << "Using second number to find first number: " << endl;
	cout << "Second Number: " << 8 << ", " << "First Number from second: " << pairlist.getFirst(8) << endl;


	cout << "--------" << endl;
	cout << "Using first number to find second number: " << endl;
	cout << "First Number: " << 5 << ", " << "Second Number from first: " << pairlist.getSecond(5) << endl << endl;


	cout << ":::: TEST 2 [CHARS] ::::" << endl;
	Pair<char> pair3;
	pair3.setFirst('A');
	pair3.setSecond('B');
	cout << pair3.getFirst() << " " << pair3.getSecond() << endl;

	cout << "--------" << endl;

	Pair<char> pair4('C', 'D');
	cout << pair4.getFirst() << " " << pair4.getSecond() << endl;

	cout << "--------" << endl;

	cout << "LIST" << endl;
	PairList<char> pairlist2;
	pairlist2.addPair('E', 'F');
	pairlist2.addPair('G', 'H');
	pairlist2.addPair('I', 'J');
	pairlist2.addPair('K', 'L');
	pairlist2.addPair('M', 'N');
	pairlist2.printList();
	cout << "--------" << endl;

	cout << "DELETE PAIR: [I,J]" << endl;
	pairlist2.deletePair('I', 'J');
	pairlist2.printList();

	cout << "--------" << endl;

	cout << "Using second letter to find first: " << endl;
	cout << "Second letter: " << 'N' << ", " << "First letter: " << pairlist2.getFirst('N') << endl;
	
	cout << "--------" << endl;

	cout << "Using first letter to find second: " << endl;
	cout << "First letter: " << 'G' << ", " << "Second letter: " << pairlist2.getSecond('G') << endl;

	return 0;
}