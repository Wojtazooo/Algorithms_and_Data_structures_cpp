#pragma once
#include <iostream>

struct elem
{
	int val;
	elem* next;
};

class OrderedLinkedList
{
private:
	elem* head;
public:
	OrderedLinkedList() : head(nullptr) {};

	void PrintAll(); // O(n)
	void Insert(int v); // optimistic O(1) pessimistic O(n) 
	elem* DelMax(); // 
};

void OrderedLinkedList::PrintAll()
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

void OrderedLinkedList::Insert(int v)
{
	elem* to_add = new elem{ v,nullptr };
	if (head == nullptr) // if list is empty
	{
		head = to_add;
		return;
	}
	if (v >= head->val) // if v > the biggest insert at the beg
	{
		to_add->next = head;
		head = to_add;
		return;
	}
	elem* p = head;
	while (p->next && p->next->val > v)
	{
		p = p->next;
	}
	to_add->next = p->next;
	p->next = to_add;
}

elem* OrderedLinkedList::DelMax()
{
	elem* max = nullptr;
	if (head == nullptr) // empty list 
		return nullptr;
	max = head;
	head = head->next;
	return max;
}
