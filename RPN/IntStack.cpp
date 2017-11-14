/*
 * IntStack.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#include "IntStack.h"

IntStack::IntStack() {
	top=-1;
}

IntStack::IntStack(const IntStack & another) {
	for (int i=0;i<=another.top;i++) {
		a[i]=another.a[i];
	}
	top=another.top;
}

IntStack::~IntStack() {
	// TODO Auto-generated destructor stub
}

int IntStack::peek() {
	return a[top];
}

int IntStack::pop() {
	int temp;
	temp=a[top];
	top--;
	return temp;
}

void IntStack::push(int n) {
	top++;
	a[top]=n;

}

void IntStack::clear() {
	top=-1;
}

int IntStack::getTop() {
	return top;
}


