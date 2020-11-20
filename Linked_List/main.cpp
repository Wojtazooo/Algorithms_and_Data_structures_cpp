#include <iostream>

struct elem
{
	int val;
	elem* next;

};

class LinkedList
{
	elem* head;

public:
	LinkedList(): head(nullptr) {};

	void PrintAll() // O(n)
	{
		elem* temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->val << " ";
			temp = temp->next;
		}
	}

	// insert at the beginning O(1)
	void Insert(int v)
	{
		elem* e = new elem{v, head};
		head = e;
	}


	void Insert_Last(int v)
	{
		if (head == nullptr) // if list is empty
		{
			head = new elem{v, nullptr};
			return;
		}
		// iterate to end of list
		elem* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new elem{ v,nullptr };
	}
};

int main()
{
	LinkedList L;
	L.Insert(1);
	L.Insert_Last(2);
	L.Insert(3);
	L.PrintAll();
}