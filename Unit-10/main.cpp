#include <iostream>
#include "PairList.h"

int main()
{
     // ========== TEST CASE 1 ==========

     LinkedList<int> list;

     list.addToEnd(1);
     list.addToEnd(2);
     list.addToEnd(3);
     list.addToEnd(4);
     list.addToEnd(5);
     list.addToEnd(6);
     list.addToEnd(7);
     list.addToEnd(8);

     cout << "============ LIST: ============" << endl;
     list.printList();
     cout << "===============================" << endl
          << endl;

     cout << "=========== INSERT: ===========" << endl;
     list.insert(8, 9);
     list.printList();
     cout << "===============================" << endl
          << endl;

     cout << "=========== DELETE: ===========" << endl;
     list.deleteNode(4);
     list.printList();
     cout << "\n4 was deleted" << endl;
     cout << "===============================" << endl
          << endl;

     cout << "========== CONTAINS?? ==========" << endl;
     cout << "Is 4 in the list? (0: False, 1: True): " << endl;
     cout << list.contains(4) << endl;
     cout << "Is 9 in the list? (0: False, 1: True): " << endl;
     cout << list.contains(9) << endl;
     cout << "===============================" << endl
          << endl;

     // ========== TEST CASE 2 ==========

     PairList<int, int> pair;
     cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
     cout << "============ LIST (INTS): ============" << endl;
     pair.addPair(1, 2);
     pair.addPair(3, 4);
     pair.addPair(5, 6);
     pair.addPair(7, 8);
     pair.addPair(9, 10);
     pair.addPair(11, 12);
     pair.addPair(13, 14);
     pair.printList();
     cout << "======================================" << endl
          << endl;

     cout << "========== GETTING: ===========" << endl;
     cout << "(" << pair.getFirst(2) << ", " << pair.getSecond(1) << ")" << endl;
     cout << "(" << pair.getFirst(4) << ", " << pair.getSecond(3) << ")" << endl;
     cout << "(" << pair.getFirst(6) << ", " << pair.getSecond(5) << ")" << endl;
     cout << "===============================" << endl
          << endl;

     cout << "========== DELETING: ==========" << endl;
     cout << "Deleting Pairs: (3, 4) & (9, 10)" << endl;
     pair.deletePair(3, 4);
     pair.deletePair(9, 10);
     pair.printList();
     cout << "===============================" << endl
          << endl;

     PairList<int, char> pair2;

     cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
     cout << "============ LIST (CHARS) ============" << endl;
     pair2.addPair(1, 'A');
     pair2.addPair(2, 'B');
     pair2.addPair(3, 'C');
     pair2.addPair(4, 'D');
     pair2.addPair(5, 'E');
     pair2.addPair(6, 'F');
     pair2.addPair(7, 'G');
     pair2.printList();
     cout << "======================================" << endl
          << endl;

     cout << "============ GETTING: ============" << endl;
     cout << "(" << pair2.getFirst('A') << ", " << pair2.getSecond(1) << ")" << endl;
     cout << "(" << pair2.getFirst('B') << ", " << pair2.getSecond(2) << ")" << endl;
     cout << "(" << pair2.getFirst('C') << ", " << pair2.getSecond(3) << ")" << endl;
     cout << "(" << pair2.getFirst('D') << ", " << pair2.getSecond(4) << ")" << endl;
     cout << "(" << pair2.getFirst('E') << ", " << pair2.getSecond(5) << ")" << endl;
     cout << "(" << pair2.getFirst('F') << ", " << pair2.getSecond(6) << ")" << endl;
     cout << "=================================" << endl
          << endl;

     cout << "============== DELETING: ==============" << endl;
     cout << "Deleting Pairs: (2, 'B') & (6, 'F')" << endl;
     pair2.deletePair(2, 'B');
     pair2.deletePair(6, 'F');
     pair2.printList();
     cout << "=======================================" << endl
          << endl;

     // ========== TEST CASE 3 ==========

     PairList<string, string> names;

     cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
     cout << "========== LISTS (STRINGS) ==========" << endl;
     names.addPair("Matthew", "Kusto");
     names.addPair("Elon", "Musk");
     names.addPair("LeBron", "James");
     names.addPair("Root", "Beer");
     names.printList();
     cout << "=====================================" << endl
          << endl;

     cout << "=========== GETTING: ===========" << endl;
     cout << "(" << names.getFirst("Kusto") << ", " << names.getSecond("Matthew") << ")" << endl;
     cout << "=====================================" << endl
          << endl;

     cout << "========== DELETING: ==========" << endl;
     cout << "Deleting Pair: Matthew Kusto" << endl;
     names.deletePair("Matthew", "Kusto");
     names.printList();
     cout << "===============================" << endl
          << endl;

     cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

     // ========== TEST CASE 4 ==========

     PairList<float, float> flt;

     cout << "============ Float List ============" << endl;
     flt.addPair(.2547, 1.7545);
     flt.addPair(.762, .7523);
     flt.addPair(4.47, 1.774);
     flt.addPair(.92145, 8.92);
     flt.addPair(.9532, 4.8742);
     flt.addPair(.2659, .784587);
     flt.addPair(.2547, 14.472);
     flt.printList();
     cout << "====================================" << endl
          << endl;

     cout << "============= GETTING: =============" << endl;
     cout << "(" << flt.getFirst(1.774) << ", " << flt.getSecond(4.47) << ")" << endl;
     cout << "====================================" << endl
          << endl;

     cout << "========== DELETING: ==========" << endl;
     cout << "Deleting Pairs: (.762, .7523) & (.2659, .784587)" << endl;
     flt.deletePair(.762, .7523);
     flt.deletePair(.2659, .784587);
     flt.printList();
     cout << "===============================" << endl
          << endl;

     return 0;
}