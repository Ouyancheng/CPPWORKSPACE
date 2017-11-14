/*
 * BinaryThreadTree.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: ouyan
 */

#include "BinaryThreadTree.h"
using namespace std;


BinaryThreadTree::BinaryThreadTree() {
	// TODO Auto-generated constructor stub
	root=NULL;
	prior=new node;

	head=prior;

	head->data='\0';
	head->lchild=root;
	head->rchild=NULL;
	head->ltag=false;
	head->rtag=true;


}

BinaryThreadTree::~BinaryThreadTree() {
	// TODO Auto-generated destructor stub
}

void BinaryThreadTree::PreorderRead(node *&p) {
	if (p == head) {
		PreorderRead(p->lchild);

	} else {
		char c=ss.get();

		if (c=='#') {
			p=NULL;
			return;
		}

		p=new node;
		p->data=c;
		p->ltag=false;
		p->rtag=false;

		if (p==head->lchild) {
			root=p;
		}

		PreorderRead(p->lchild);
		PreorderRead(p->rchild);
	}
	return;
}

void BinaryThreadTree::PreorderReadTree(string s) {
	ss << s;
	PreorderRead(head);
	ss.clear();
	return;
}

void BinaryThreadTree::InorderTraverse(node *&p) {
	if (p!=NULL) {
		InorderTraverse(p->lchild);

		cout << p->data << " ";
		if (p->lchild==NULL) {
			p->ltag=true;
			p->lchild=prior;
		}

		if (prior->rchild==NULL) {
			prior->rtag=true;
			prior->rchild=p;
		}

		prior=p;
		InorderTraverse(p->rchild);
	}

	return;
}

void BinaryThreadTree::InorderThreading() {
	InorderTraverse(root);
	cout << endl << prior->data << endl;
	head->rchild=prior;
	prior->rtag = true;
	prior->rchild=head;

	return;
}

void BinaryThreadTree::InorderTraverse_NonRecursion(node *&p) {
	node *q;
	q=p->lchild;

	while (q!=p) {
		while (q->ltag==false) {
			q=q->lchild;
		}
		cout << q->data << " ";

		while (q->rtag==true && q->rchild!=p) {
			q=q->rchild;
			cout << q->data << " ";
		}
		q=q->rchild;
	}

}
