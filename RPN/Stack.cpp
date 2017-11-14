/*
 * Stack.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#include "Stack.h"

Stack::Stack() {
	top=-1;
}

Stack::Stack(const Stack & another) {
	for (int i=0;i<=another.top;i++) {
		a[i]=another.a[i];
	}
	top=another.top;
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

char Stack::peek() {
	return a[top];
}

char Stack::pop() {
	char temp;
	temp=a[top];
	top--;
	return temp;
}

void Stack::push(char c) {
	top++;
	a[top]=c;
}

void Stack::clear() {
	top=-1;
}

int Stack::getTop() {
	return top;
}

