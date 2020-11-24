#include "Linkedlist.h"
#include "OrderedLinkedList.h"
#include "Heap.h"
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
		Heap H(10000);
		srand(time(NULL));
		for (int i = 1; i < 50; i++)
		{
			H.Insert(rand()%100);
		}
		H.Show();
	}

	
}
