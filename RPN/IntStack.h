/*
 * IntStack.h
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#ifndef INTSTACK_H_
#define INTSTACK_H_

class IntStack {
public:
	IntStack();
	IntStack(const IntStack & another);
	virtual ~IntStack();

	int peek();
	int pop();
	void push(int n);

	void clear();

	int getTop();

private:
	int a[255];
	int top;
};

#endif /* INTSTACK_H_ */
