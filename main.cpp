#include "LinkedList/LinkedList.h"

int main()
{
	LinkedList L;
	L.Insert_Last(1);
	L.Insert(2);
	L.Insert_Last(30);
	L.Insert(4);
	L.Insert(5);
	L.Insert_Last(6);
	L.Insert(50);
	L.PrintAll();
	std::cout << "Delmax\n";
	L.DelMax();
	L.PrintAll();
	std::cout << "Delmax\n";
	L.DelMax();
	L.PrintAll();
}