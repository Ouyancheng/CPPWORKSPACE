/*
 * main.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: ouyan
 */

#include "StaticLinklist.h"
#include <iostream>
using namespace std;

int main() {
	Static_Linklist l1;
	/*l1.push_back(1);
	cout << l1 << endl;
	l1.push_back(6);
	cout << l1 << endl;
	l1.push_back(8);
	cout << l1 << endl;
	l1.push_back(9);
	cout << l1 << endl;*/

	for (int i=0;i<=12;i++) {
		l1.push_back(i);
	}
	cout << l1 << endl;
	l1.showArray();

	l1.insertElem(2,6);
	cout << l1 << endl;
	l1.showArray();

	l1.deleteElem(5);
	cout << l1 << endl;
	l1.showArray();

	cout << l1.getElem(6) << endl;

	l1.deleteElem(4);
	cout << l1 << endl;
	l1.showArray();

	l1.deleteElem(5);
	cout << l1 << endl;
	l1.showArray();

	return 0;
}


