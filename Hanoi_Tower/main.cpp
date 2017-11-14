/*
 * main.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: ouyan
 */

#include <iostream>
#include <cstdio>
using namespace std;

void move(int n, char x, char y, char z) {
	if (n==1) {
		//cout << x << "-->" << z << endl;
		printf("%c-->%c ",x,z);
	} else {
		move(n-1,x,z,y);
		//cout << x << "-->" << z << endl;
		printf("%c-->%c ",x,z);
		move(n-1,y,x,z);
	}
}

int main() {
	int n;
	cin >> n;
	move(n,'x','y','z');

	return 0;
}
