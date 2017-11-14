#pragma once
#include "Node.h"
#include <iostream>
#include <stack>
#include <queue>
class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	void insertElement(int element);

	int popMinElement();

	int popMaxElement();

	bool deleteElement(int element);

	void inorderTraverse();
	void inorderTraverse(node *p);

	void preorderTraverse();
	void preorderTraverse(node *p);

	void postorderTraverse();
	void postorderTraverse(node *p);

	void layerTraverse();

	bool searchElement(int element);

	void LRotate(node *&p);
	void RRotate(node *&p);

	unsigned int getSize();

	unsigned int getHeight(node *p);

	node * getRoot();
	node * root;
private:
	
	unsigned int size;

	void deleteTree(node *p);

};

