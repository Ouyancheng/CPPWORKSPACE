/*
 * Linklist.h
 *
 *  Created on: Aug 8, 2016
 *      Author: ouyan
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_
#include "Node.h"
#include <iostream>
using namespace std;


class Linklist {
public:
	Linklist();
	virtual ~Linklist();

	void push_back(qnode element);

	qnode pop_head();

	void insert(qnode element);

	int getLength();

	friend ostream & operator <<(ostream &os, Linklist &l);

private:
	qnode *head;
	int length;
};

#endif /* LINKLIST_H_ */
