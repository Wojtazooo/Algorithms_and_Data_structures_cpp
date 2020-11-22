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

