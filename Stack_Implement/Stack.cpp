/*
 * Stack.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: ouyan
 */

#include "Stack.h"

Stack::Stack() {
	// TODO Auto-generated constructor stub
	a=new int[10];
	top=a;
	size=10;
	length=0;
}

Stack::Stack(int n) {
	a=new int[n];
	top=a;
	size=n;
	length=0;
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
	if (a!=NULL) {
		delete [] a;
	}
}

void Stack::push(int element) {
	if (length==size) {
		int *p;
		int *temp;
		temp=a;

		p=new int[2*size];
		size*=2;

		for (int i=0;i<length;i++) {
			p[i]=a[i];
		}
		p[length]=element;
		++length;
		top=&p[length];
		a=p;

		delete [] temp;

	} else {
		*(top)=element;
		++top;
		++length;
	}
}

int Stack::pop() {
	if (top==a) {
		return 0;
	}
	--top;
	--length;
	return *(top);
}

int Stack::peek() {
	if (top==a) {
		return 0;
	}
	int *temp;
	temp=top;
	--temp;
	return *(temp);
}

void Stack::clear() {
	top=a;
}

void Stack::destroy() {
	delete [] a;
	a=NULL;
	top=NULL;
	size=0;
	length=0;
}

int Stack::getSize() {
	return size;
}

int Stack::getLength() {
	return length;
}

