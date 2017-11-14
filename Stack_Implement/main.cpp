/*
 * main.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: ouyan
 */

#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
	Stack s;

	for (int i=0;i<=9;i++) {
		s.push(i);
	}

	cout << "Length: " << s.getLength() << "      Size: " << s.getSize() << endl;
	s.push(10);
	cout << "Length: " << s.getLength() << "      Size: " << s.getSize() << endl;

	for (int i=0;i<=9;i++) {
		cout << s.pop() << " ";
	}
	cout << s.pop() << endl;

	s.clear();
	cout << "Length: " << s.getLength() << "      Size: " << s.getSize() << endl;

	return 0;
}


