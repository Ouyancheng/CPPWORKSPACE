/*
 * Queue.h
 *
 *  Created on: Jul 31, 2016
 *      Author: ouyan
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Node.h"
#include <iostream>
using namespace std;


class Queue {
public:
	Queue();
	virtual ~Queue();

	void push(int element);
	int pop();

	void clear();

	friend ostream & operator <<(ostream &os, Queue &q);

private:
	node *front;
	node *rear;
	int length;
};

#endif /* QUEUE_H_ */
