/*
 * main.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: ouyan
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int BinarySearch(const string& a, char search) {
	//bool found = 0;
	int index = -1;
	int left;
	int right;
	int middle;
	left = 0;
	right = a.size() - 1;
	middle = (left + right) / 2;
	while (search != a[middle]) {
		if (left + 1 == right) {
			if (a[left] != search && a[right] != search) {
				//found = false;
				break;
			} else if (a[left] == search) {
				//found = true;
				index = left;
				break;
			} else {
				//found = true;
				index = right;
				break;
			}
		}
		if (search > a[middle]) {
			left = middle;
			middle = (left + right) / 2;
		} else {
			right = middle;
			middle = (left + right) / 2;
		}
	}
	if (search == a[middle]) {
		index = middle;
		//found = true;
	}
	return index;
}

int main() {
	string a;
	cin >> a;
	sort(&a[0],&a[a.size()-1]+1);
	cout << a << endl;

	char search;
	cin >> search;

	int index = BinarySearch(a, search);
	if (index!=-1) {
		cout << "Found! In " << index << endl;
	} else {
		cout << "Not found! " << endl;
	}

	return 0;
}


