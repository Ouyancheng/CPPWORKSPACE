/*
 * Linklist.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: ouyan
 */

#include "Linklist.h"


Linklist::Linklist() {
	// TODO Auto-generated constructor stub
	head=new node;
	head->data=0;
	head->next=NULL;
	length=0;
}

Linklist::~Linklist() {
	// TODO Auto-generated destructor stub
	node *p;
	node *q;
	p=head;
	while (p) {
		q=p->next;
		delete p;
		p=q;
	}
	head=NULL;
}

void Linklist::insertHead(int element) {
	node *p;
	p=new node;
	p->data=element;
	p->next=head->next;
	head->next=p;
	++length;
}

void Linklist::insertTail(int element) {
	node *p;
	node *q;

	p=head;
	while (p->next) {
		p=p->next;
	}

	q=new node;
	q->data=element;
	q->next=NULL;
	p->next=q;

	++length;
}

int & Linklist::getElem(int index) {
	int i=0;
	node *p;
	p=head;
	while ((p)&&(i<=index)) {
		p=p->next;
		++i;
	}

	if (!p) {
		return head->data;
	}

	return p->data;

}

bool Linklist::insertElem(int index, int element) {
	node *p;
	node *q;
	int i=0;
	p=head;

	//The while loop can take pointer p to the node just before the index node.
	while ((p)&&(i<index)) {
		p=p->next;
		++i;
	}

	if (!p) {
		return 0;
	}

	q=new node;
	q->data=element;

	if (!(p->next)) {
		p->next=q;
		q->next=NULL;
		++length;
		return 1;
	}

	q->next=p->next;
	p->next=q;
	++length;
	return 1;
}

bool Linklist::deleteElem(int index) {
	node *p;
	node *q;
	p=head;

	int i=0;

	//This while loop can take pointer p to the node just before the index node.
	while ((p)&&(i<index)) {
		p=p->next;
		++i;
	}

	if (!p) {
		return 0;
	}

	if (!(p->next)) {
		return 0;
	}

	q=p->next;
	p->next=p->next->next;
	delete q;
	--length;
	return 1;
}

int & Linklist::getMidNode() {
	node *search, *mid;
	if (head->next==NULL) {
		return head->data;
	}

	search=head->next;
	mid=head->next;
	while (search->next!=NULL) {
		if (search->next->next!=NULL) {
			search=search->next->next;
			mid=mid->next;
		} else {
			search=search->next;
		}
	}
	return mid->data;
}

void Linklist::clear() {
	node *p;
	node *q;
	p=head->next;
	while (p) {
		q=p->next;
		delete p;
		p=q;
	}
	length=0;
	head->next=NULL;
}

ostream & operator <<(ostream & os, Linklist & l) {
	node *p;
	p=l.head->next;

	os << "Length: " << l.length << endl;
	os << "Element: " << endl;
	while (p) {
		os << p->data << " ";
		p=p->next;
	}

	return os;
}
