#include "Linkedlist.h"
#include "OrderedLinkedList.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "Splay.h"
#include "Sorting_algorithms.h"

elem* OddEvenPartition(elem*& head)
{
	elem* oddfirst = nullptr, *evenfirst = nullptr, *evenlast = nullptr, *oddlast = nullptr;
	elem* prev = nullptr;
	elem* p = head;

	while (p != nullptr)
	{
		if (p->val % 2 != 0) // element jest nieparzysty
		{
			if (oddfirst == nullptr) // natrafiliśmy na pierwszy nieparzysty element
			{
				oddfirst = p;
				oddlast = p;
			}
			else if (prev->val % 2 != 0) // poprzedni też był NP więc przedłużamy
			{
				oddlast = p;
			}
			else // poprzedni był P więc wydłużamy ścieżkę nieparzystych
			{
				oddlast->next = p;
				oddlast = p;
			}
		}
		else // element jest parzysty
		{
			if (evenfirst == nullptr) // natrafiliśmy na pierwszy parzysty element
			{
				evenfirst = p;
				evenlast = p;
			}
			else if (prev->val % 2 == 0) // poprzedni też był P więc przedłużamy
			{
				evenlast = p;
			}
			else // poprzedni był NP więc wydłużamy naszą parzystą ścieżkę
			{
				evenlast->next = p;
				evenlast = p;
			}
		}
		prev = p;
		p = p->next;
	}

	if(evenlast != nullptr) evenlast->next = oddfirst;
	if (oddlast != nullptr) oddlast->next = nullptr;
	head = evenfirst;

	return oddfirst;
}


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






	
}
