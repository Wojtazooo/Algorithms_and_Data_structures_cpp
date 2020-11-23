#pragma once
#include <iostream>

struct elem
{
	int val;
	elem* next;
};

class LinkedList
{
private:
	elem* head;
public:
	LinkedList() : head(nullptr) {};

	void PrintAll(); // O(n)
	void Insert(int v); // insert at the beginning O(1)
	void Insert_Last(int v); // insert at the end O(n)
	elem* DelMax(); // optimistic O(1) pessimistic O(n)
};

#include "Linkedlist.h"


void LinkedList::PrintAll()
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

void LinkedList::Insert(int v)
{
	elem* e = new elem{ v, head };
	head = e;
}

void LinkedList::Insert_Last(int v)
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

elem* LinkedList::DelMax()
{
	elem* max = head; // pointer to max elem
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
