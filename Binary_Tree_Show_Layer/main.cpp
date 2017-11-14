/*
 * main.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: ouyan
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree t;
	t.createNode(t.root);
	t.preorder(t.root, 1);

	return 0;
}


