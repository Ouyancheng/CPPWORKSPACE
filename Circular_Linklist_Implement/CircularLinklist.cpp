/*
 * CircularLinklist.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: ouyan
 */

#include "CircularLinklist.h"

int tmp=0;

Circular_Linklist::Circular_Linklist() {
	// TODO Auto-generated constructor stub
	head = NULL;
	length = 0;
}

Circular_Linklist::~Circular_Linklist() {
	// TODO Auto-generated destructor stub
	if (head == NULL) {
		length = 0;
	} else {
		node *p, *q;
		p = head;

		while (p->next != head) {
			q = p->next;
			delete p;
			p = q;
		}
		delete p;
		p = NULL;
		head = NULL;
	}
}

bool Circular_Linklist::push_back(int element) {
	if (head == NULL) {
		head = new node;
		head->data = element;
		head->next = head;
	} else {
		node *p;
		node *q;
		p = head;
		while (p->next != head) {
			p = p->next;
		}
		q = new node;
		q->data = element;
		q->next = head;
		p->next = q;
	}
	++length;
	return true;
}

bool Circular_Linklist::insertElem(int index, int element) {
	if ((index < 0) || (index > length)) {
		return false;
	}

	if (index==length) {
		return push_back(element);
	}

	node *p;
	node *q;
	p = head;
	for (int j = 0; j < index-1; j++) {
		p = p->next;
	}
	q=new node;
	q->data=element;
	q->next=p->next;
	p->next=q;
	++length;
	return true;
}

bool Circular_Linklist::deleteElem(int index) {
	if ((index<0)||(index>=length)) {
		return false;
	}
	if (head->next==head) {
		delete head;
		head=NULL;
		--length;
		return true;
	}
	if (index==0) {
		node *p;
		p=head;
		head=head->next;
		delete p;
		--length;
		return true;
	}

	node *p;
	node *q;
	p=head;
	while (p->next!=head) {
		p=p->next;
	}

	for (int i=0;i<index;i++) {
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	q=NULL;
	--length;
	return true;
}

int & Circular_Linklist::getElem(int index) {
	if ((index<0)||(index>=length)) {
		return tmp;
	}

	node *p;
	p=head;
	for (int i=0;i<index;i++) {
		p=p->next;
	}
	return p->data;
}

int Circular_Linklist::search(int element) {
	node *p;
	p=head;
	int i=0;
	while (p->data!=element && i<length) {
		p=p->next;
		++i;
	}
	return i;
}
