/*
 * main.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: ouyan
 */

#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
	Queue q;
	for (int i=6;i<=18;i++) {
		q.push(i);
	}
	cout << q << endl;

	cout << q.pop() << endl;
	cout << q << endl;


	q.clear();
	cout << q << endl;

	return 0;
}


