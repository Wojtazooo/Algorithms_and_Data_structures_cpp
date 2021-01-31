#pragma once

// To do:
// - UnionFindTree constructor

struct UnionFindNode
{
	UnionFindNode* father;
	int setNo;
};

class UnionFindTree
{
private:
	UnionFindNode** elemArr;
	UnionFindNode** setArr;
	int n;
public:
	
	int Find(int elemNo); 
	void Union(int s1, int s2, int sOut);
};

int UnionFindTree::Find(int elemNo)
{
	// find root
	UnionFindNode* p = elemArr[elemNo];
	while (p->father != nullptr)
		p = p->father;
	UnionFindNode* root = p;

	// path compression
	p = elemArr[elemNo];
	while (p->father != nullptr) 
	{
		UnionFindNode* pt = p->father;
		p->father = root;
		p = pt;
	}
	return root->setNo;
}

void UnionFindTree::Union(int s1, int s2, int sOut)
{
	UnionFindNode* root1 = setArr[s1];
	UnionFindNode* root2 = setArr[s2];

	root1->father = root2;
	root2->setNo = sOut;

	setArr[s1] = nullptr;
	setArr[s2] = nullptr;
	setArr[sOut] = root2;
}