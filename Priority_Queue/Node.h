/*
 * Node.h
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
using namespace std;
struct qnode
{
	int data;
	qnode *lchild;
	qnode *rchild;

	qnode *parent;

	qnode(int data = 0, qnode *parent = NULL) :
			data(data), lchild(NULL), rchild(NULL), parent(parent)
	{
	}
};

#endif /* NODE_H_ */
