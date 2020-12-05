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
	void PrintAll();
	void InOrder_print(bst_node* act);
	void PreOrder_print(bst_node* act);
	void PostOrder_print(bst_node* act);
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
		std::cout << "item with key = "<<v<<" already exists\n";
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

void Binary_Search_Tree::PrintAll()
{
	std::cout << "Preorder: "; PreOrder_print(root); std::cout << std::endl;
	std::cout << "Inorder: "; InOrder_print(root); std::cout << std::endl;
	std::cout << "Postorder: "; PostOrder_print(root); std::cout << std::endl;
}

void Binary_Search_Tree::PreOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	std::cout << act->key << " ";
	PreOrder_print(act->left);
	PreOrder_print(act->right);
}

void Binary_Search_Tree::InOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	InOrder_print(act->left);
	std::cout << act->key << " ";
	InOrder_print(act->right);
}

void Binary_Search_Tree::PostOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	PostOrder_print(act->left);
	PostOrder_print(act->right);
	std::cout << act->key << " ";
}