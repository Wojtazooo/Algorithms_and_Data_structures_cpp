#pragma once
#include <climits>
#include <cmath>
#include <iomanip>

// Heap implemented in array
class Heap
{
	int* tab; 
	int hl; // an index of the last elem in heap
public:
	Heap(int size = 100) 
	{
		tab = new int[size];
		tab[0] = INT_MAX; 
		hl = 0;
	}

	void Insert(int val);
	void UpHeap(int id); 
	void Show();
	void Print();



};


void Heap::Insert(int val)
{
	tab[++hl] = val;
	UpHeap(hl);
}

void Heap::UpHeap(int id)
{
	int val = tab[id];
	int i = id;
	int p;
	while (tab[i] > tab[i/2]) // because the tab[0] = int_max we will exit this loop
	{
		p = tab[i];
		tab[i] = tab[i / 2];
		tab[i / 2] = p;
		i = i / 2;
	}
}

void Heap::Show()
{
	int h = (log2(hl) + 1); // heap height
	int spaces = pow(2, h-1) - 1; // spaces between numbers	

	// with log10 we can compute the width of the widthest element = the biggest
	//it will allow to adjust size of one elem
	int width = (log10(tab[1])) + 1; 
	
	int nr_to_print = 1;
	std::cout << std::setw(width);
	while (1)
	{
		for (int i = nr_to_print; i < nr_to_print*2 && i <= hl; i++)
		{
			if (i == nr_to_print)
			{
				for (int j = 0; j < spaces; j++)
				{
					std::cout << std::setw(width) << ' ';
				}
			}
			else
			{
				for (int j = 0; j < 2*spaces+1; j++)
				{
					std::cout << std::setw(width) << ' ';
				}
			}
			std::cout << std::setw(width) << tab[i];
		}
		std::cout << "\n";
		spaces /= 2;
		nr_to_print *= 2;
		if (nr_to_print > hl)
			break;
	}
}

void Heap::Print()
{
	std::cout << "Heap elems: ";
	for (int i = 1; i < hl; i++)
	{
		std::cout << tab[i] << " ";
	}
	std::cout << "\n";
}

