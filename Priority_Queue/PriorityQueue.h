/*
 * PriorityQueue.h
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include "Node.h"
class PriorityQueue
{
public:
	PriorityQueue();
	virtual ~PriorityQueue();

	void insert(int data);

	int pop_smallest();

	void InorderTraverse(qnode *p);

	void PreorderTraverse(qnode *p);

	void PostorderTraverse(qnode *p);

	qnode *getRoot();
	qnode *getLeftmost();
	int getLength();

private:
	qnode *root;
	qnode *leftmost;
	unsigned int length;

	void deleteNode(qnode *p);
};

#endif /* PRIORITYQUEUE_H_ */
