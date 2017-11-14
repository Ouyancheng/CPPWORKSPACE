/*
 * Queue.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#include "Queue.h"

Queue::Queue() {
	// TODO Auto-generated constructor stub
	head=new qnode;
	head->data="";
	head->index=0;
	head->next=NULL;
	tail=head;
	length=0;
}

Queue::~Queue() {
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

void Queue::push_back(string vertex, int index) {
	qnode *p;
	p=new qnode;
	p->data=vertex;
	p->index=index;
	p->next=NULL;
	tail->next=p;
	tail=tail->next;
	++length;
}

int Queue::pop_front() {
	if (length==0) {
		return -1;
	}
	qnode *p;
	p=head->next;
	head->next=p->next;
	int i;
	i=p->index;
	p->next=NULL;
	delete p;
	--length;
	if (length==0) {
		tail=head;
	}
	return i;
}

int Queue::getLength() {
	return length;
}

