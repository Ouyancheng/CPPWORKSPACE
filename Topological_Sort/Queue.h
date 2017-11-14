/*
 * Queue.h
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Node.hpp"
class Queue {
public:
	Queue();
	virtual ~Queue();

	void push_back(const unsigned int &element);

	qnode pop_front();

	unsigned int getLength() const;

private:
	qnode *head;
	qnode *tail;
	unsigned int length;
};

#endif /* QUEUE_H_ */
