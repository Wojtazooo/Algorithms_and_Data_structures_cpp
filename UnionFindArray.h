#pragma once
#include<iomanip>

class UnionFindArray
{
private:
	int* R;
	int n;

public:
	UnionFindArray(int n, int* init_sets);
	int Find(int i); // O(1) returns an index of a set
	void Union(int s1, int s2, int s3); // O(n)

	void Print();
};


UnionFindArray::UnionFindArray(int n, int* init_sets)
{
	this->n = n;
	R = new int[n];
	for (int i = 0; i < n; i++)
		R[i] = init_sets[i];
}

inline int UnionFindArray::Find(int i)
{
	return R[i];
}

void UnionFindArray::Union(int s1, int s2, int s3)
{
	for (int i = 0; i < n; i++)
	{
		if (R[i] == s1 || R[i] == s2)
			R[i] = s3;
	}
}

void UnionFindArray::Print()
{
	std::cout << "id:  ";
	for (int i = 0; i < n; i++)
		std::cout << std::setw(3) << i;
	std::cout << "\nset: ";
	for (int i = 0; i < n; i++)
		std::cout << std::setw(3) << R[i];
	std::cout << "\n";
}