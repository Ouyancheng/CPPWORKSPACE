/*
 * Stack.h
 *
 *  Created on: Jul 28, 2016
 *      Author: ouyan
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>

using namespace std;


class Stack {
public:
	Stack();
	Stack(int n);
	virtual ~Stack();

	void push(int element);

	int pop();

	int peek();

	void clear();
	void destroy();

	int getSize();
	int getLength();

private:
	int *a;
	int size;
	int length;
	int *top;
};

#endif /* STACK_H_ */
