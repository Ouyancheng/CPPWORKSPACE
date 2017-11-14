/*
 * Stack.h
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#ifndef STACK_H_
#define STACK_H_

class Stack {
public:
	Stack();
	Stack(const Stack & another);
	virtual ~Stack();

	char peek();
	char pop();
	void push(char c);

	void clear();

	int getTop();

private:
	char a[255];
	int top;
};

#endif /* STACK_H_ */
