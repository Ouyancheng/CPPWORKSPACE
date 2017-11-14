/*
 * Queue.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#include "Queue.h"

Queue::Queue() {
	// TODO Auto-generated constructor stub
	head=new qnode(0u);
	tail=head;
	length=0u;
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

void Queue::push_back(const unsigned int &element) {
	tail->next=new qnode(element);
	tail=tail->next;
	++length;
}

qnode Queue::pop_front() {
	if (length==0u) {
		return qnode(0u);
	}

	qnode *p;
	p=head->next;
	head->next=p->next;

	qnode result(0u);
	result=*p;
	delete p;

	--length;

	if (length==0u) {
		tail=head;
	}
	return result;
}

unsigned int Queue::getLength() const {
	return length;
}

