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

int PartitionOddEven(int* tab, int l, int r)
{
	// iterator z lewej strony wywalający nieparzyste na lewo i iterator z prawej wywalający 
	int i = 0;
	int j = r-l;

	while (i < j)
	{
		while (i < j && tab[i] % 2 == 0)  // iterator idący z lewej strony zatrzymujący się na nieparzystej
			i++;
		while (j > i&& tab[j] % 2 == 1) //  iterator idący z prawej strony zatrzymujący się na parzystej
			j--;
		int tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
	}

	// tu wychodzę to czy na pewno i == j? czy może być i > j
	std::cout << "i = " << i << " j = " << j << "\n";
	return i;

}

void QuickSortOddEven(int* tab, int l, int r)
{
	int k = PartitionOddEven(tab, l, r);
	if (k - 1 > l) QuickSort(tab, l, k - 1);
	if (k + 1 < r) QuickSort(tab, k, r);
}

void ListPartition(elem *& head, elem*& g_head, elem *&g_tail,elem *&piv_head,elem *&piv_tail,elem *&s_head,elem *&s_tail)
{
	elem* p = head;
	int v = head->val;

	// utworzenie listy z elementami pivot
	piv_head = head;
	piv_tail = head;
	p = p->next;

	while (p != nullptr)
	{
		if (p->val > v) // greater
		{
			if (g_head == nullptr) {
				g_head = p;
				g_tail = p;
			}
			else {
				g_tail->next = p;
				g_tail = g_tail->next;
				
			}

		}
		else if (p->val == v) // dodajemy do listy pivotow
		{
			piv_tail->next = p;
			piv_tail = piv_tail->next;

		}
		else
		{ // smaller
			if (s_head == nullptr) {
				s_head = p;
				s_tail = p;
			}
			else {
				s_tail->next = p;
				s_tail = s_tail->next;
				
			}
		}
		p = p->next;
	}

	if (g_tail != nullptr) g_tail->next = nullptr;
	if (piv_tail != nullptr) piv_tail->next = nullptr;
	if (s_tail != nullptr) s_tail->next = nullptr;
}

void ListQuickSort(elem*& head, elem*& tail)
{
	if (head == tail)
		return;
	elem* g_head = nullptr, * g_tail = nullptr, * piv_head = nullptr, * piv_tail = nullptr, * s_head = nullptr, * s_tail = nullptr;

	ListPartition(head, g_head, g_tail, piv_head, piv_tail, s_head, s_tail); // wszystkie wskaźniki z góry
	ListQuickSort(s_head, s_tail);
	ListQuickSort(g_head, g_tail);

	// złączenie w jedną listę
	if (s_head != nullptr && g_head != nullptr) // mniejsze i większe istnieją
	{
		head = s_head;
		s_tail->next = piv_head;
		piv_tail->next = g_head;
		tail = g_tail;
	}
	else if (s_head != nullptr) // tylko mniejsze od v istnieja
	{
		head = s_head;
		s_tail->next = piv_head;
		tail = piv_tail;
	}
	else if (g_head != nullptr) // tylko większe
	{
		head = piv_head;
		piv_tail->next = g_head;
		tail = g_tail;
	}
	else // tylko pivoty
	{
		head = piv_head;
		tail = piv_tail;
	}
}