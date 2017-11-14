/*
 * main.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: ouyan
 */

#include <iostream>
#include "KMP_Algorithm.h"
using namespace std;

int main() {
	string a;
	string b;

	cin >> a >> b;

	cout << KMP_Search(a,b,0) << endl;

	return 0;
}
