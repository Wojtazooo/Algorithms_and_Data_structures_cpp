
bool check_if_sorted(int* tab, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (tab[i] < tab[i - 1]) return false;
	}
	return true;
}

void Print_tab(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
}

void SelectionSort(int* tab, int size)
{
	int i = 0;
	while (i < size)
	{
		int j = i+1;
		int min_id = i;
		while (j < size)
		{
			if (tab[j] < tab[min_id])
			{
				min_id = j;
			}
			j++;
		}
		int tmp = tab[min_id];
		tab[min_id] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

void InsertionSort(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (tab[j] < tab[j - 1])
			{
				int tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
			else
				break;
		}
	}
}

void BubbleSort(int* tab, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				int tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}

void MixSort(int* tab, int size)
{
	int l = 0;
	int r = size - 1;
	int k = 1;

	do
	{
		for (int i = l; i < r; i++)
			if (tab[i] > tab[i + 1])
			{
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				k = i;
			}
		r = k;
		for (int i = r; i >= l; i--)
			if (tab[i] > tab[i + 1])
			{
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				k = i;
			}
		l = k + 1;
	} while (l <= r);
}	

int Partition(int* tab, int l, int r)
{
	int v = tab[l];
	int i = l;
	int j = r + 1;
	do
	{
		do i++; while (tab[i] < v);
		do j--; while (tab[j] > v);
		if (i < j)
		{
			int tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
	} while (i < j);
	tab[l] = tab[j];
	tab[j] = v;
	return j;
}

void QuickSort(int*tab, int l, int r)
{
	int k = Partition(tab, l, r);
	if(k-1 > l) QuickSort(tab, l, k - 1);
	if(k+1 < r) QuickSort(tab, k + 1, r);
}