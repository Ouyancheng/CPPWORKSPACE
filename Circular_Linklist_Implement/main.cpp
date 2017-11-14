/*
 * main.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: ouyan
 */

#include "CircularLinklist.h"
#include <iostream>
using namespace std;

int main() {
	Circular_Linklist l1;

	l1.push_back(1);
	cout << l1 << endl;

	l1.push_back(2);
	cout << l1 << endl;

	for (int i=0;i<=9;i++) {
		l1.push_back(i);
	}
	cout << l1 << endl;

	l1.insertElem(2,6);
	cout << l1 << endl;

	cout << l1.getElem(2) << endl;

	l1.deleteElem(7);
	cout << l1 << endl;

	cout << l1.search(9) << endl;
	cout << l1.search(1) << endl;
	cout << l1.search(6) << endl;


	return 0;
}
