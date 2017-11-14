/*
 * main.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: ouyan
 */

#include "Linklist.h"
#include <iostream>

using namespace std;

void test() {
	Linklist l1;
	cout << l1 << endl;

	l1.insertTail(0);
	cout << l1 << endl;
	for (int i = 1; i <= 9; i++) {
		l1.insertHead(i);
	}
	cout << l1 << endl;

	l1.insertElem(2, 6);
	cout << l1 << endl;

	l1.deleteElem(6);
	cout << l1 << endl;

	for (int i = 0; i <= 6; i++) {
		cout << l1.getElem(i) << " ";
	}
	cout << endl;

	cout << l1.insertElem(100,99) << endl;
	cout << l1 << endl;

	cout << l1.deleteElem(1024) << endl;
	cout << l1 << endl;

	//l1.clear();
	//cout << l1 << endl;

	l1.deleteElem(5);
	cout << l1 << endl;
	cout << l1.getMidNode() << endl;
}

int main() {
	test();

	return 0;
}
