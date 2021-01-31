#pragma once
#include <tuple>
#include <cmath>
#include <iostream>
#include <iomanip>

class Beap
{
private:
	int* tab;
	int size;
	int hl; 
public:

	Beap(int size = 100);
	int ij2k(int i, int j);
	std::tuple<int, int> k2ij(int k);
	void Insert(int v);
	void UpHeap(int k);
	void DownBeap(int k);
	int DelMax();
	int Max();
	int Search(int v);

	void Print();
};

Beap::Beap(int size)
{
	this->size = size+1;
	tab = new int[size+1];
	tab[0] = INT_MAX;
	hl = 0;
}

int Beap::ij2k(int i, int j)
{
	// sum of arithmetic sequence (previous elements) + column j of i row
	return i * (i - 1) / 2 + j; 
}

std::tuple<int, int> Beap::k2ij(int k)
{
	int i = (int)(ceil(0.5 * (-1 + std::sqrt(1.0 + 8 * k))));
	int j = (int)(k - 0.5 * i * (i - 1));
	return std::make_tuple(i, j);
}

void Beap::Insert(int v)
{
	tab[++hl] = v;
	UpHeap(hl);
}

void Beap::UpHeap(int k)
{
	// move to smaller one
	int i, j;
	std::tie(i, j) = k2ij(k);
	int x = tab[k];
	   
	int k1 = k;
	while (i > 1)
	{
		if (j == 1) // only right parent
		{
			k = k - i + 1;
		}
		else if (j == i) // the last elem in a row -> only left parent
		{
			k = k - i;
			j--;
		}
		else // 2 parents we will move to a smaller one
		{
			// we assume that the left parent is greater
			k = k - i;
			j--;
			if (tab[k] > tab[k + 1]) // if the right parent is greater move to him
			{
				k++;
				j++;
			}
		}
		// check if a smaller parent is greater than its child
		if (tab[k] < x)
		{
			tab[k1] = tab[k];
			k1 = k;
			i--;
		}
		else
			break;
	}
	tab[k1] = x;
}

void Beap::DownBeap(int k)
{
	int x = tab[k];
	int i, j;
	std::tie(i, j) = k2ij(k);

	int k1 = k;
	k = k + i; // left child
	i++;
	while (k <= hl)
	{
		if (k < hl)
		{
			if (tab[k + 1] > tab[k]) // if right child is greater
			{
				k++;
			}
		}
		if (tab[k] > x) 
		{
			tab[k1] = tab[k];
			k1 = k;
			k = k + i;
			i++;
		}
		else
			break;
	}
}

int Beap::DelMax()
{
	int to_ret = tab[1];
	tab[1] = tab[hl];
	hl--;
	DownBeap(1);
	return to_ret;
}

int Beap::Max()
{
	return tab[1];
}

int Beap::Search(int v)
{
	int i, j, k;

	std::tie(i, j) = k2ij(hl);
	if (i != j)
	{
		j = --i;
	}

	k = ij2k(i, j);

	while (v != tab[k] && j > 0)
	{
		if (v > tab[k]) // move up left
		{
			i--;
			j--;
			k = ij2k(i, j);
		}
		else if (v < tab[k])
		{
			if (ij2k(i + 1, j) <= hl) // move down left
			{
				i++;
				k = ij2k(i, j);
			}
			else // move to left
			{
				j--;
				k--;
			}
		}
	}
	if (tab[k] == v) return k;
	return 0;
}

void Beap::Print()
{
	int i, j;
	for (int id = 1; id <= hl; id++)
	{
		std::tie(i, j) = k2ij(id);
		std::cout << std::setw(4) <<tab[id];
		if (i == j) std::cout << "\n";
	}
	std::cout << "\n";
}
