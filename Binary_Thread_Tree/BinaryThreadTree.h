/*
 * BinaryThreadTree.h
 *
 *  Created on: Aug 7, 2016
 *      Author: ouyan
 */

#ifndef BINARYTHREADTREE_H_
#define BINARYTHREADTREE_H_
#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class BinaryThreadTree {
public:
	BinaryThreadTree();
	virtual ~BinaryThreadTree();

	void PreorderReadTree(string s);

	void InorderTraverse(node *&p);

	void InorderThreading();

	void InorderTraverse_NonRecursion(node *&p);

//private:
	node *head;
	node *root;
	node *prior;
	stringstream ss;

	void PreorderRead(node *&p);
};

#endif /* BINARYTHREADTREE_H_ */
