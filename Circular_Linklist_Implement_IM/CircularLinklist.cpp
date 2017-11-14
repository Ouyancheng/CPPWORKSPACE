/*
 * CircularLinklist.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: ouyan
 */

#include "CircularLinklist.h"

Circular_Linklist::Circular_Linklist() {
	// TODO Auto-generated constructor stub
	rear = new node;
	rear->data = 0;
	rear->next = rear;
	length = 0;
}

Circular_Linklist::~Circular_Linklist() {
	// TODO Auto-generated destructor stub
	node *p;
	node *q;
	p = rear;
	while (p->next != rear) {
		q = p->next;
		delete p;
		p = q;
	}
	delete p;
}

void Circular_Linklist::push_back(int element) {
	node *p;
	p = new node;
	p->data = element;
	p->next = rear->next;
	rear->next = p;

	rear = p;
	++length;
}

bool Circular_Linklist::insertElem(int index, int element) {
	if (index < 0 || index > length) {
		return false;
	}
	if (index == length) {
		push_back(element);
		return true;
	}

	node *p;
	node *q;
	p = rear->next;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	q = new node;
	q->data = element;
	q->next = p->next;
	p->next = q;
	++length;
	return true;
}

bool Circular_Linklist::deleteElem(int index) {
	if (index < 0 || index >= length) {
		return false;
	}

	node *p;
	p = rear->next;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}

	node *q;
	q = p->next;

	p->next = q->next;
	delete q;
	--length;
	return true;
}

int & Circular_Linklist::getElem(int index) {
	if (index < 0 || index >= length) {
		return rear->next->data;
	}

	if (index == length) {
		return rear->data;
	}
	if (index == 0) {
		return rear->next->next->data;
	}

	node *p;
	p = rear;
	for (int i = 0; i <= index + 1; i++) {
		p = p->next;
	}
	return p->data;
}

bool Circular_Linklist::empty() {
	if (rear->next==rear) {
		return true;
	} else {
		return false;
	}
}

ostream & operator <<(ostream &os, Circular_Linklist &l) {
	os << "Length: " << l.length << endl;
	os << "Empty? " << l.empty() << endl;
	os << "Element: " << endl;
	node *p;
	p = l.rear;
	p = p->next;
	while (p->next != l.rear) {
		p = p->next;
		os << p->data << " ";
	}
	os << p->next->data << " ";
	return os;
}
