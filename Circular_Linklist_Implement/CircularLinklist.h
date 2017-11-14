/*
 * CircularLinklist.h
 *
 *  Created on: Jul 25, 2016
 *      Author: ouyan
 */

#ifndef CIRCULARLINKLIST_H_
#define CIRCULARLINKLIST_H_
#include "Node.h"
#include <iostream>
using namespace std;


class Circular_Linklist {
public:
	Circular_Linklist();
	virtual ~Circular_Linklist();

	bool push_back(int element);

	bool insertElem(int index, int element);
	bool deleteElem(int index);

	int & getElem(int index);

	int search(int element);

	friend ostream & operator <<(ostream &os, Circular_Linklist &l) {
		os << "Length: " << l.length << endl;
		node *p;
		p=l.head;
		os << "Element(s): " << endl;
		while (p->next!=l.head) {
			os << p->data << " ";
			p=p->next;
		}
		os << p->data << " ";
		return os;
	}

private:
	node *head;
	int length;
};

#endif /* CIRCULARLINKLIST_H_ */
