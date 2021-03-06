﻿#include "Linkedlist.h"
#include "OrderedLinkedList.h"
#include "Heap.h"
#include "Beap.h"
#include "BinarySearchTree.h"
#include "Splay.h"
#include "Sorting_algorithms.h"
#include "RST.h"
#include "UnionFindArray.h"




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
		std::cout << "==================\n";
	}


	std::cout << "Elementary sorting algorithms\n\n";

	// Selection Sort
	{
		std::cout << "Selection Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = rand() % (5 * size) + 1;
		}
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
		
		SelectionSort(tab, size);
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
	}

	// Insertion Sort
	{
		std::cout << "\nInsertion Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = rand() % (5 * size) + 1;
		}
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
		
		InsertionSort(tab, size);
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
	}

	// Bubble Sort
	{
		std::cout << "\nBubble Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = rand() % (5 * size) + 1;
		}
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";

		BubbleSort(tab, size);
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
	}

	std::cout << "==================\n";
	
	// Mix Sort
	{
		std::cout << "\nMix Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = rand() % (5 * size) + 1;
		}
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";

		MixSort(tab, size);
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
	}

	// Quick Sort
	{
		std::cout << "\nnQuick Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = rand() % (5 * size) + 1;
		}
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";

		QuickSort(tab, 0, size - 1);
		Print_tab(tab, size);
		std::cout << "is sorted? ";
		check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
	}

	// OddEvenQuick Sort
	{
		std::cout << "OddEvenQuick Sort\n";

		int size = 20;
		int* tab = new int[size];
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < size; i++)
			{
				tab[i] = rand() % (5 * size) + 1;
			}
			std::cout << "-------------------------\n";
			Print_tab(tab, size);
			std::cout << "is sorted? ";
			check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";

			QuickSortOddEven(tab, 0, size - 1);
			Print_tab(tab, size);
			std::cout << "is sorted? ";
			check_if_sorted(tab, size) == true ? std::cout << "Yes\n" : std::cout << "No\n";
		}
	}

	// OddEven LinkedList
	{
		std::cout << "--------------------------\n";
		LinkedList L;

		int size = 100;
		for (int i = 0; i < size; i++)
		{
			L.Insert(rand() % (5 * size) + 1);
		}

		elem* tail = L.head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}


		std::cout << "Given linked list\n";
		L.PrintAll();
		std::cout << "Sorted Linked List\n";
		ListQuickSort(L.head, tail);
		L.PrintAll();
	}

	//  RST
	{
		std::cout << "--------------------------\n";
		RST rst(8,10);

		std::cout << "przed\n";
		rst.PrintAll();


		int size = 10;
		for (int i = 0; i < size; i++)
		{
			rst.Insert(rand() % (5 * size) + 1);
		}
				
		std::cout << "po\n";
		rst.PrintAll();
	}

	// UnionFindArray
	{
		std::cout << "--------------------------\n";
		int n = 10;
		int* sets = new int[n];

		for (int i = 0; i < n; i++)
		{
			sets[i] = rand() % (n / 2) + 1;
		}
		UnionFindArray ufarray(n, sets);
		ufarray.Print();
		ufarray.Union(1, 2, 5);
		std::cout << "After union 1 and 2 to 5: \n";
		ufarray.Print();
	}

	// Beap
	{
		std::cout << "--------------------------\n";
		std::cout << "BEAP\n";
		int size = 20;
		Beap beap(size+1);
		for (int i = 0; i < size; i++)
		{
			beap.Insert((rand() % (2 * size)) + 1);
		}

		beap.Insert(1);
		beap.Print();

		std::cout << "Index of 1: " << beap.Search(1) << "\n";
		std::cout << "Index of 10: " << beap.Search(10) << "\n";
		std::cout << "Index of 20: " << beap.Search(20) << "\n";
		std::cout << "Index of 30: " << beap.Search(30) << "\n";



	}
}
