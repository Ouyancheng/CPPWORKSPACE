/*
 * BinaryTree.h
 *
 *  Created on: Aug 6, 2016
 *      Author: ouyan
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "Node.h"

class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();

	void createNode(node *(&p));

	void preorder(node *p, int layer);

	node *root;

};

#endif /* BINARYTREE_H_ */
