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

