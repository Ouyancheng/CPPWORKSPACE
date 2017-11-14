/*
 * Linklist.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: ouyan
 */

#include "Linklist.h"

Linklist::Linklist() {
	// TODO Auto-generated constructor stub
	length=0;
	head=new qnode;
	head->count=0;
	head->ispointer=false;
	head->next=NULL;
	head->data.c='\0';
}

Linklist::~Linklist() {
	// TODO Auto-generated destructor stub
	qnode *p;
	qnode *q;
	p=head;
	while (p->next!=NULL) {
		q=p->next;
		delete p;
		p=q;
	}
	delete p;
}

void Linklist::push_back(qnode element) {
	qnode *p;
	p=head;
	while (p->next!=NULL) {
		p=p->next;
	}

	p->next=new qnode;
	p->next->count=element.count;
	p->next->ispointer=element.ispointer;
	p->next->data=element.data;
	p->next->next=NULL;

	++length;
}

qnode Linklist::pop_head() {
	qnode *p;
	p=head->next;
	head->next=p->next;
	--length;
	qnode q;
	q=*(p);
	delete p;
	return q;
}

void Linklist::insert(qnode element) {
	qnode *p;
	p=head;
	qnode *q;
	q=new qnode;
	q->count=element.count;
	q->data=element.data;
	q->ispointer=element.ispointer;

	while (p->next != NULL && p->next->count <= element.count) {
		p=p->next;
	}
	if (p->next!=NULL) {
		q->next=p->next;
		p->next=q;
		++length;
	} else {
		p->next=q;
		q->next=NULL;
		++length;
	}

	return;
}

int Linklist::getLength() {
	return length;
}

ostream & operator <<(ostream &os, Linklist &l) {
	qnode *p;
	p=l.head->next;
	os << "Length: " << l.length << endl;
	os << "Element(s): " << endl;
	while (p!=NULL) {
		os << "Count: " << p->count << " Data: " << p->data.c << endl;
		p=p->next;
	}
	return os;
}
