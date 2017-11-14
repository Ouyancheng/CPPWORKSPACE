/*
 * mainExec.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: ouyan
 */

#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
	Vector v1;
	cout << v1 << endl;
	for (int i=1;i<=9;i++) {
		v1.push_back(i);
	}
	cout << v1 << endl;

	v1.insertElem(10,5);
	cout << v1 << endl;

	v1.push_back(18);
	cout << v1 << endl;

	v1.deleteElem(3);
	cout << v1 << endl;

	v1.resize(10);
	cout << v1 << endl;

	v1.resize(6);
	cout << v1 << endl;

	v1.resize(18);
	cout << v1 << endl;

	for (int i=0;i<=v1.getLength()-1;i++) {
		cout << v1[i] << " ";
	}

	v1.reverse();
	cout << v1 << endl;

	v1.deleteElem(2);
	cout << v1 << endl;

	v1.reverse();
	cout << v1 << endl;
	return 0;
}


