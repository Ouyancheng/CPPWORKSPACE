/*
 * BinaryTree.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: ouyan
 */

#include "BinaryTree.h"
#include <cstdio>
#include <iostream>
using namespace std;
BinaryTree::BinaryTree() {
	// TODO Auto-generated constructor stub
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub


}

void BinaryTree::createNode(node *(&p)) {
	char c;
	//scanf("%c", &c);
	c=cin.get();
	if (c == '#') {
		p = nullptr;
		return;
	}
	if (root == nullptr) {
		p = new node;
		p->data = c;
		p->lchild = nullptr;
		p->rchild = nullptr;
		root = p;

		//printf("Created %c! \n", c);

		createNode(p->lchild);
		createNode(p->rchild);
	} else {
		p = new node;
		p->data = c;
		p->lchild = nullptr;
		p->rchild = nullptr;

		//printf("Created %c! \n", c);

		createNode(p->lchild);
		createNode(p->rchild);
	}
}

void BinaryTree::preorder(node *p, int layer) {
	if (p != nullptr) {
		cout << p->data << " in layer " << layer << endl;
		preorder(p->lchild, layer + 1);
		preorder(p->rchild, layer + 1);
	} else {
		return;
	}
}

