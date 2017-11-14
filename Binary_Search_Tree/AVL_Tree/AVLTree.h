#pragma once
#include "Node.h"
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
class AVLTree
{
public:
	AVLTree();
	virtual ~AVLTree();
	void delSub(tnode *p);
	
	void InorderTraverse(tnode *p);
	void PreorderTraverse(tnode *p);
	void PostorderTraverse(tnode *p);
	void LayerTraverse(tnode *p);
	
	tnode * getRoot();
	int getHeight(tnode *p);

	void LRotate(tnode *&p);
	void RRotate(tnode *&p);

	bool addElem(int element);

	//bool delElem(int element);

	void show();
	

private:
	tnode *root;
};

