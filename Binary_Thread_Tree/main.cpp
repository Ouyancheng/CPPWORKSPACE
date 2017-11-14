/*
 * main.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: ouyan
 */

#include "BinaryThreadTree.h"
using namespace std;

int main() {
	BinaryThreadTree btt;
	string a;
	cin >> a;
	btt.PreorderReadTree(a);

	btt.InorderThreading();

	btt.InorderTraverse_NonRecursion(btt.head);

	return 0;
}


