/*
 * Linklist.h
 *
 *  Created on: Jul 23, 2016
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

	void insertHead(int element);
	void insertTail(int element);

	int & getElem(int index);

	bool insertElem(int index, int element);
	bool deleteElem(int index);

	int & getMidNode();

	void clear();

	friend ostream & operator <<(ostream & os, Linklist & l);

private:
	node *head;
	int length;
};

#endif /* LINKLIST_H_ */
