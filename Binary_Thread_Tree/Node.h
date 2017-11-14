/*
 * Node.h
 *
 *  Created on: Aug 7, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_


struct node {
	char data;
	bool ltag;
	bool rtag;
	node *lchild;
	node *rchild;
};


#endif /* NODE_H_ */
