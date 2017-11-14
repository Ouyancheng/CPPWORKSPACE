/*
 * QNode.h
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#ifndef QNODE_H_
#define QNODE_H_
#include <string>

struct qnode {
	std::string data;
	int index;
	qnode *next;
};



#endif /* QNODE_H_ */
