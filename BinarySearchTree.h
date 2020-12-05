#pragma once
#include<iostream>

struct bst_node
{
	int key;
	bst_node* left, *right;
};

class Binary_Search_Tree
{
private:
	bst_node* root;
public:
	Binary_Search_Tree():root(nullptr){};
	bst_node* Search(int v, bst_node* &prev);
	void Insert(int v);
};

bst_node* Binary_Search_Tree::Search(int v, bst_node* &prev) // previous element for insert method
{
	bst_node* p = root;
	while (p != nullptr)
	{
		if (v == p->key)
			break;
		if (v < p->key)
		{
			prev = p;
			p = p->left;
		}
		else
		{
			prev = p;
			p = p->right;
		}
	}
	return p;
}

void Binary_Search_Tree::Insert(int v)
{
	bst_node* prev = nullptr;
	bst_node* p = Search(v, prev);

	if (p != nullptr)
	{
		std::cout << "item already exists in this BST tree\n";
		return;
	}
	bst_node* pnew = new bst_node{ v, nullptr, nullptr };
	if(root == nullptr)
	{
		root = pnew; 
		std::cout << "inserting first item\n";
		return;
	}
	if (prev->key < v)
		prev->right = pnew;
	else
		prev->left = pnew;
	
}

