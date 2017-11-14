/*
 * CircularLinklist.h
 *
 *  Created on: Jul 26, 2016
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

	void push_back(int element);

	bool insertElem(int index, int element);
	bool deleteElem(int index);

	int & getElem(int index);

	bool empty();

	friend ostream & operator <<(ostream &os, Circular_Linklist &l);

private:
	node *rear;
	int length;
};

#endif /* CIRCULARLINKLIST_H_ */
