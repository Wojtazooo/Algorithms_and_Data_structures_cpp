#include "Linkedlist.h"
#include "OrderedLinkedList.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "Splay.h"
int main()
{
	// LinkedList test
	{
		std::cout << "==================\n";
		std::cout << "Linked list\n";
		LinkedList L;
		L.Insert(1); L.Insert(2); L.Insert_Last(5); L.Insert(4);
		L.PrintAll();
		std::cout << "Delmax\n";
		L.DelMax();
		L.PrintAll();
		std::cout << "==================\n";

	}

	// OrderedLinkedList test
	{
		std::cout << "Ordered linked list\n";
		OrderedLinkedList OL;
		OL.Insert(2);
		OL.Insert(3);
		OL.Insert(1);
		OL.Insert(5);
		OL.Insert(2);
		OL.PrintAll();
		std::cout << "Delmax\n";
		OL.DelMax();
		OL.PrintAll();
		std::cout << "==================\n";
	}

	// Heap test
	{
		std::cout << "Heap: \n";
		Heap H(100);
		srand(time(NULL));
		for (int i = 1; i < 15; i++)
		{
			int val = rand() % 50 + 1;
			std::cout << "Insert: " << val << std::endl;
			H.Insert(val);
			H.Show();
			std::cout << "---------------\n";
		}
		H.DelMax();
		std::cout << "Delmax\n";
		H.Show();
		std::cout << "==================\n";
	}

	// Binary Search Tree test
	{
		std::cout << "Binary Search Tree: \n";
		Binary_Search_Tree BST;
		BST.Insert('b');
		BST.Insert('a');
		BST.Insert('c');

		BST.PrintAll();		
		std::cout << "---------------\n";
		std::cout << "Binary Search Tree double pointers insert\n";
		Binary_Search_Tree BST2;
		BST2.Insert2(20);
		BST2.Insert2(10);
		BST2.Insert2(30);
		BST2.Insert2(15);
		BST2.Insert2(25);
		BST2.PrintAll();
		std::cout << "==================\n";
	}

	// SplayTree
	{
		std::cout << "Splay Tree: \n";
		Splay_Tree ST;
		Binary_Search_Tree BST;

		for (int i = 1; i <= 10; i++)
		{
			ST.Insert(i);
			BST.Insert(i);
		}
		std::cout << "after inserts:\n";
		ST.PrintAll();
		std::cout << "RIGHT: \n";
		ST.Print_right();
		std::cout << "LEFT: \n";
		ST.Print_left();

		std::cout << "Search: 1,2\n";
		ST.Search(1);
		ST.Search(2);
		ST.PrintAll();
		std::cout << "RIGHT: \n";
		ST.Print_right();
		std::cout << "LEFT: \n";
		ST.Print_left();

		std::cout << "---------------\n";

		std::cout << "\nBinary Tree with the same elements: \n";
		BST.PrintAll();
	}
	
}
