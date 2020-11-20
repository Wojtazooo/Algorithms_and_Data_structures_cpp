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
			std::cout << temp->val;
			if (temp->next != nullptr)
				std::cout << " -> ";
			else
				std::cout << "\n";
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
		elem* to_add = new elem{ v, nullptr };
		if (head == nullptr) // if list is empty
		{
			head = to_add;
			return;
		}
		// iterate to end of list
		elem* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = to_add;
	}

	elem* DelMax()
	{
		elem *max = head; // pointer to max elem
		elem* smax = nullptr; // shadow of max elem
		elem* temp = head; 
		elem* stemp = nullptr; // shadow of temp
		while (temp)
		{
			if (temp->val > max->val)
			{
				smax = stemp;
				max = temp;
			}
			stemp = temp;
			temp = temp->next;
		}
		if (max != nullptr) // if list is not empty
		{
			if (smax != nullptr) // if max is not first elem in list
				smax->next = max->next;
			else // max is at the beginning
				head = max->next;
		}
		return max;
	}
};

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