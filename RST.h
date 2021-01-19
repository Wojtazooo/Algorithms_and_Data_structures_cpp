#pragma once
#include<iostream>

void bin(unsigned n,int maxb)
{
	unsigned i;
	for (i = 1 << maxb-1; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
}

int bit(int x, int i)
{
	return (x >> i) & 1;
}

struct rst_node
{
	int key;
	rst_node* next[2];

	rst_node(int k) { key = k; next[0] = next[1] = nullptr; };
};

class RST
{
private:
	rst_node* root;
	int maxb;
public:

	RST(int maxb, int root_val);
	rst_node** Search(int v);
	void Insert(int v);
	void Delete(int val);
	void InOrder(rst_node* p);
	void PreOrder(rst_node* p);
	void PostOrder(rst_node* p);
	void Printroot();
	void PrintAll();
};

void RST::Printroot()
{
	std::cout << "root = " << root->key << std::endl;
}

RST::RST(int maxb, int root_val)
{
	this->maxb = maxb;
	this->root = new rst_node(root_val);
}

rst_node** RST::Search(int key)
{
	rst_node** p = &root;
	int i = maxb;

	while ((*p) && i >= 0 && (*p)->key != key) 
	{
		if (bit(key, i) == 1) // go right
			p = &(*p)->next[1];
		else if (bit(key, i) == 0) // go left
			p = &(*p)->next[0];
		i--;
	}
	return p;
}

void RST::Insert(int key)
{
	rst_node** p = Search(key);
	if (*p != nullptr) return; // if key exists
	else
	{
		*p = new rst_node(key);
	}
	//std::cout << "insert: " << key << std::endl;
	//InOrder(root);
}

void RST::Delete(int val)
{
	rst_node** p = Search(val);

	// jeśli element do usunięcia nie istnieje -> nie ma co usuwać, więc wychodzimy
	if (*p == nullptr) return;
	
	// jeśli element jest liściem -> usuwamy
	if ((*p)->next[0] == nullptr && (*p)->next[1] == nullptr)
	{
		*p = nullptr;
		return;
	}
	// jeśli element nie jest liściem -> szukamy liścia, zamieniamy miejscami i usuwamy liść
	rst_node** leaf = p;

	while ((*leaf)->next[0] != nullptr || (*leaf)->next[1] != nullptr)
	{
		if ((*leaf)->next[0] != nullptr) // left exists
			leaf = &(*leaf)->next[0];
		else // right exists
			leaf = &(*leaf)->next[1];
	}

	rst_node* pl = (*p)->next[0];
	rst_node* pr = (*p)->next[1];

	(*p) = (*leaf);
	
	(*leaf) = nullptr;

	(*p)->next[0] = pl;
	(*p)->next[1] = pr;

	if ((*p)->next[0] == (*p)) (*p)->next[0] = nullptr;
	if ((*p)->next[1] == (*p)) (*p)->next[1] = nullptr;

}

inline void RST::InOrder(rst_node* p)
{
	if (p == nullptr) return;
	InOrder(p->next[0]);
	bin(p->key, maxb);
	std::cout << " = " << p->key <<  " \n";
	InOrder(p->next[1]);
}
inline void RST::PreOrder(rst_node* p)
{
	if (p == nullptr) return;
	bin(p->key, maxb);
	std::cout << " = " << p->key << " \n";
	PreOrder(p->next[0]);
	PreOrder(p->next[1]);
}
inline void RST::PostOrder(rst_node* p)
{
	if (p == nullptr) return;
	PostOrder(p->next[0]);
	PostOrder(p->next[1]);
	bin(p->key, maxb);
	std::cout << " = " << p->key << " \n";
}

void RST::PrintAll()
{
	std::cout << "PreOrder\n";
	PreOrder(root);
	std::cout << "InOrder\n";
	InOrder(root);
	std::cout << "PostOrder\n";
	PostOrder(root);
}