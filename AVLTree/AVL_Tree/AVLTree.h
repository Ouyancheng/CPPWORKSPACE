/*
 * AVLTree.h
 *
 *  Created on: Aug 26, 2016
 *      Author: ouyan
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include "Node.h"
#include <stack>
class AVLTree {
public:
	AVLTree();
	virtual ~AVLTree();

	bool insertElem(int element);

	bool deleteElem(int element);

	void InorderTraverse();
	void PreorderTraverse();

private:
	node *root;

	void rightbalance(node *&p);
	void leftbalance(node *&p);

	void rotateLeft(node *&p);
	void rotateRight(node *&p);
};

#endif /* AVLTREE_H_ */
