#include "BinaryTree.h"
#include "WordCount.h"
#include <cstdlib>

int main()
{
    BinaryTree<int> bt;
    cout << "==================" << endl;
    cout << ":::::BINARY TEST:::::" << endl;
    bt.insert(10);
    bt.insert(15);
    bt.insert(5);
    bt.insert(7);
    bt.insert(4);
    bt.insert(11);
    bt.insert(17);
    bt.printTree();
    cout << "++++++++++++++++++" << endl;
    cout << "Max: " << bt.findMax() << endl;
    cout << "Min: " << bt.findMin() << endl;
    cout << "++++++++++++++++++" << endl;
    cout << "Contains 9?: " << bt.contains(9) << endl;
    cout << "Contains 7?: " << bt.contains(7) << endl;
    cout << "++++++++++++++++++" << endl;
    cout << "Removed 5: " << endl;
    bt.remove(10);
    bt.remove(4);
    bt.printTree();
    cout << "++++++++++++++++++" << endl;

    cout << "==================" << endl;
    cout << ":::::AVL TEST:::::" << endl;
    AvlTree<int> avl;
    for (int i = 1; i < 56; i++)
    {
        avl.insert(i);
    }
    avl.printTree();
    cout << "++++++++++++++++++" << endl;
    cout << "Is tree empty?: " << avl.isEmpty() << endl;
    cout << "++++++++++++++++++" << endl;
    cout << "Max: " << avl.findMax() << endl;
    cout << "Min: " << avl.findMin() << endl;
    cout << "++++++++++++++++++" << endl;
    cout << "Contains 15?: " << avl.find(15) << endl;
    cout << "Contains 55?: " << avl.find(55) << endl;
    cout << "Contains 70?: " << avl.find(70) << endl;
    cout << "++++++++++++++++++" << endl;
    avl.remove(10);
    avl.remove(50);
    avl.remove(44);
    avl.remove(26);
    avl.remove(34);
    avl.remove(17);
    avl.printTree();
    cout << "++++++++++++++++++" << endl;
    avl.makeEmpty();
    avl.printTree();
    cout << "Is tree empty?: " << avl.isEmpty() << endl;
    cout << "==================" << endl;

	cout << "::::::FILEIO::::::" << endl;
	WordCount wc;
	wc.readFile("WordCountTest-1.txt");
	wc.printFile();
	cout << "++++++++++++++++++" << endl;

    return 0;
}