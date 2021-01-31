#pragma once

class UnionFindArray
{
private:
	int* R;
	int n;

public:
	UnionFindArray(int n);
	int Find(int i); // returns an index of a set

};


UnionFindArray::UnionFindArray(int n)
{
	this->n = n;
	this->R = new int[n];
}

inline int UnionFindArray::Find(int i)
{
	return R[i];
}