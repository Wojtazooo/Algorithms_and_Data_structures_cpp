#pragma once
#include "BinarySearchTree.h"

class Splay_Tree
{
private:
	bst_node* root;
public:
	Splay_Tree();
	void Splay(int v, bst_node* &root);
	void Insert(int v);
	bst_node* Search(int v);
	

	// left rotations
	void LZig(bst_node* &root);
	void LZigZig(bst_node* &root);
	void LZigZag(bst_node* &root);

	// right rotations
	void RZig(bst_node* &root);
	void RZigZig(bst_node* &root);
	void RZigZag(bst_node* &root);

	void PrintAll();
	void InOrder_print(bst_node* act);
	void PreOrder_print(bst_node* act);
	void PostOrder_print(bst_node* act);
	void Print_right();
	void Print_left();
};

void Splay_Tree::LZig(bst_node* &root)
{
	bst_node* y = root;
	bst_node* x = root->left;
	bst_node* a = root->left->left;
	bst_node* b = root->left->right;
	bst_node* c = root->right;

	root = x;
	x->left = a;
	x->right = y;
	y->left = b;
	y->right = c;
}

void Splay_Tree::LZigZig(bst_node*& root)
{
	bst_node* z = root;
	bst_node* y = root->left;
	bst_node* x = root->left->left;

	bst_node* a = x->left;
	bst_node* b = x->right;
	bst_node* c = y->right;
	bst_node* d = z->right;

	root = x;
	root->left = a;
	root->right = y;
	y->left = b;
	y->right = z;
	z->left = c;
	z->right = d;
}

void Splay_Tree::LZigZag(bst_node*& root)
{
	bst_node* z = root;
	bst_node* w = root->left;
	bst_node* x = root->left->right;
	
	bst_node* a = w->left;
	bst_node* b = x->left;
	bst_node* c = x->right;
	bst_node* d = z->right;

	root = x;
	x->left = w;
	x->right = z;
	w->left = a;
	w->right = b;
	z->left = c;
	z->right = d;
}

void Splay_Tree::RZig(bst_node*& root)
{
	bst_node* x = root;
	bst_node* y = root->right;

	bst_node* a = x->left;
	bst_node* b = y->left;
	bst_node* c = y->right;

	root = y;
	y->right = c;
	x->left = a;
	x->right = b;
}

void Splay_Tree::RZigZig(bst_node*& root)
{
	bst_node* x = root;
	bst_node* y = x->right;
	bst_node* z = y->right;
	   
	bst_node* a = x->left;
	bst_node* b = y->left;
	bst_node* c = z->left;
	bst_node* d = z->right;

	root = z;
	z->right = d;
	z->left = y;
	y->right = c;
	y->left = x;
	x->left = a;
	x->right = b; 
}

void Splay_Tree::RZigZag(bst_node*& root)
{
	bst_node* z = root;
	bst_node* w = z->right;
	bst_node* x = w->left;

	bst_node* a = z->left;
	bst_node* b = x->left;
	bst_node* c = x->right;
	bst_node* d = w->right;

	root = x;
	x->left = z;
	x->right = w;
	z->left = a;
	z->right = b;
	w->left = c;
	w->right = d;
}

Splay_Tree::Splay_Tree()
{
	root = nullptr;
}

void Splay_Tree::Splay(int v, bst_node*& root)
{
	if (v < root->key) // v is in left subtree
	{
		if (root->left) // if left node exists 
		{
			if (v < root->left->key) // left left?
				if (root->left->left) // left left
				{
					Splay(v, root->left->left);
					LZigZig(root);
				}
				else // left
					LZig(root);
			else if (v > root->left->key) // left right?
				if (root->left->right) // left right
				{
					Splay(v, root->left->right);
					LZigZag(root);
				}
				else // left
					LZig(root);
		}
	}
	else if (v > root->key) // is v in right subtree
	{
		if (root->right) // can we move to right?
		{
			if (v < root->right->key) // right left?
				if (root->right->left) // right left
				{
					Splay(v, root->right->left);
					RZigZag(root);
				}
				else // right
					RZig(root);
			else if(v > root->right->key) // right right?
				if (root->right->right) // right right
				{
					Splay(v, root->right->right);
					RZigZig(root);
				}
				else // right
					RZig(root);
		}
	}
}

bst_node* Splay_Tree::Search(int v)
{
	if (!root)
		return nullptr;
	Splay(v, root);
	if (root->key == v)
		return root;
	else
		return nullptr;
}

void Splay_Tree::Insert(int v)
{
	if (!root)
	{
		root = new bst_node;
		root->key = v;
		root->left = root->right = nullptr;
	}
	else
	{
		Splay(v, root);
		if (root->key < v) // v is new root and actual root is left child of new root
		{
			bst_node* p = new bst_node;
			p->key = v;
			p->left = root;
			p->right = root->right;
			root->right = nullptr;
			root = p;
		}
		else if (root->key > v)
		{
			bst_node* p = new bst_node;
			p->key = v;
			p->right = root;
			p->left = root->left;
			root->left = nullptr;
			root = p;
		}
		// if root->key == v we dont insert new elem
	}
}

void Splay_Tree::PrintAll()
{
	std::cout << "Preorder: "; PreOrder_print(root); std::cout << std::endl;
	std::cout << "Inorder: "; InOrder_print(root); std::cout << std::endl;
	std::cout << "Postorder: "; PostOrder_print(root); std::cout << std::endl;
}

void Splay_Tree::PreOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	std::cout << act->key << " ";
	PreOrder_print(act->left);
	PreOrder_print(act->right);
}

void Splay_Tree::InOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	InOrder_print(act->left);
	std::cout << act->key << " ";
	InOrder_print(act->right);
}

void Splay_Tree::PostOrder_print(bst_node* act)
{
	if (act == nullptr) return;
	PostOrder_print(act->left);
	PostOrder_print(act->right);
	std::cout << act->key << " ";
}

void Splay_Tree::Print_right()
{
	int counter = 0;
	bst_node* p = root;
	while (p != nullptr)
	{
		std::cout << p->key << std::endl;
		p = p->right;
		counter++;
	}
}

void Splay_Tree::Print_left()
{
	int counter = 0;
	bst_node* p = root;
	while (p != nullptr)
	{
		std::cout << p->key << std::endl;
		p = p->left;
		counter++;
	}
}