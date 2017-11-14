/*
 * KMP_Algorithm.h
 *
 *  Created on: Aug 4, 2016
 *      Author: ouyan
 */

#ifndef KMP_ALGORITHM_H_
#define KMP_ALGORITHM_H_

#include <string>
using namespace std;


int * calculateNext(string a) {
	int * next;
	int length=a.size();
	next=new int[length];

	next[0]=length-1;
	next[1]=0;

	int i;
	int j;
	i=1;
	j=0;

	do {
		if (j==0 || a[i]==a[j]) {
			++i;
			++j;
			if (a[i]!=a[j]) {
				next[i]=j;
			} else {
				next[i]=next[j];
			}

		} else {
			j=next[j];
		}
	} while (i<length-1);

	return next;
}

//Return the position of the substring in the main string after pos characters
int KMP_Search(string a, string sub, int pos) {
	string b=" ";
	b.append(sub);

	int *next;
	next=calculateNext(b);

	unsigned int i=pos;
	unsigned int j=1;

	while (i<a.size() && j<b.size()) {
		if (j==0 || a[i]==b[j]) {
			i++;
			j++;
		} else {
			j=next[j];
		}
	}

	cout << next[0] << endl;
	for (unsigned int i=1;i<b.size();i++) {
		cout << next[i] << " ";
	}
	cout << endl;

	delete [] next;

	if (j>=b.size()) {
		return i-b.size()+1;
	} else {
		return -1;
	}
}

#endif /* KMP_ALGORITHM_H_ */