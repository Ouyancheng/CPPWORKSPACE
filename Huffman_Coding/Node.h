/*
 * Node.h
 *
 *  Created on: Aug 8, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_

struct tnode;

union udata {
	char c;
	tnode *p;
};

struct tnode {
	udata data;
	bool ispointer;
	int count;
	tnode *lchild;
	tnode *rchild;
};



struct qnode {
	udata data;
	int count;
	bool ispointer;
	qnode *next;
};

struct cnode {
	char c;
	int count;
};


#endif /* NODE_H_ */
