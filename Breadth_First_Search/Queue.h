/*
 * Queue.h
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "QNode.h"
using namespace std;
class Queue {
public:
	Queue();
	virtual ~Queue();

	void push_back(string vertex, int index);

	int pop_front();

	int getLength();

private:
	qnode *head;
	qnode *tail;
	int length;
};

#endif /* QUEUE_H_ */
