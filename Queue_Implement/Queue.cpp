/*
 * Queue.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: ouyan
 */

#include "Queue.h"

Queue::Queue() {
	// TODO Auto-generated constructor stub
	front=new node;
	front->next=nullptr;
	front->data=0;
	rear=front;
	length=0;
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
	node *p;
	node *q;
	p=front;
	while (p->next!=nullptr) {
		q=p->next;
		delete p;
		p=q;
	}
	delete p;
}

void Queue::push(int element) {
	node *p;
	p=new node;
	p->data=element;
	p->next=nullptr;
	rear->next=p;
	rear=p;
	++length;
}

int Queue::pop() {
	if (front==rear || front->next==nullptr) {
		return 0;
	}

	node *p;
	p=front->next;
	int n=p->data;
	if (p->next==nullptr) {
		rear=front;
		front->next=nullptr;
		delete p;
		--length;
		return n;
	} else {
		front->next=p->next;
		delete p;
		--length;
		return n;
	}
	return n;
}

void Queue::clear() {
	node *p;
	node *q;

	if (front==rear) {
		return;
	}

	p=front->next;
	while (p->next!=nullptr) {
		q=p->next;
		delete p;
		p=q;
	}

	delete p;
	rear=front;
	front->next=nullptr;
	length=0;
}

ostream & operator <<(ostream &os, Queue &q) {
	node *p;
	p=q.front;
	os << "Length: " << q.length << endl;
	os << "Element(s): " << endl;
	while (p->next!=nullptr) {
		p=p->next;
		os << p->data << " ";
	}
	//os << p->data << endl;

	return os;
}

