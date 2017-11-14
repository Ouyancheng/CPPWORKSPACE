/*
 * AVLTree.cpp
 *
 *  Created on: Aug 26, 2016
 *      Author: ouyan
 */

#include "AVLTree.h"

AVLTree::AVLTree() {
	// TODO Auto-generated constructor stub
	root=NULL;
}

AVLTree::~AVLTree() {
	// TODO Auto-generated destructor stub
}

bool AVLTree::insertElem(int element) {
	if (root == NULL) {
		root = node(element);
		return true;
	}

	node *p=root;
	node *pre=NULL;
	position pos;
	stack<snode> Stack;

	while (p!=NULL) {
		if (element < p->data) {
			Stack.push(snode(p,  position::L));
			pre=p;
			pos=position::L;
			p=p->lchild;
		} else if (element > p->data) {
			Stack.push(snode(p, position::R));
			pre=p;
			pos=position::R;
			p=p->rchild;
		} else {
			return false;
		}
	}

	if (pos==position::L) {
		pre->lchild=new node(element);
		p=pre->lchild;
	} else {
		pre->rchild=new node(element);
		p=pre->rchild;
	}

	position prep=position::L;
	position pprep=position::R;

	do {
		if (Stack.top().p->bf==0 && Stack.top().pos==position::L) {
			++Stack.top().p->bf;
			//continue;
		} else if (Stack.top().p->bf==0 && Stack.top().pos==position::R) {
			--Stack.top().p->bf;
			//continue;
		} else if (Stack.top().p->bf==1 && Stack.top().pos==position::R) {
			--Stack.top().p->bf;
			break;
		} else if (Stack.top().p->bf==-1 && Stack.top().pos==position::L) {
			++Stack.top().p->bf;
			break;
		} else if (Stack.top().p->bf==1 && Stack.top().pos==position::L) {
			rightbalance(Stack.top().p);
			break;
		} else if (Stack.top().p->bf==-1 && Stack.top().pos==position::R) {
			leftbalance(Stack.top().p);
			break;
		}
		Stack.pop();
	} while (Stack.empty());





}


void AVLTree::rotateLeft(node *&p) {
	node *temp;
	temp=p;
	p=p->rchild;
	temp->rchild=p->lchild;
	p->lchild=temp;
	p->bf=EH;
	--temp->bf;
}

void AVLTree::rotateRight(node *&p) {
	node *temp;
	temp=p;
	p=p->lchild;
	temp->lchild=p->rchild;
	p->rchild=temp;
	p->bf=EH;
	++temp->bf;
}


