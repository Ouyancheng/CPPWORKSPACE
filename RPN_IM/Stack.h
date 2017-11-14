/*
 * Stack.h
 *
 *  Created on: Jul 19, 2016
 *      Author: ouyan
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>
typedef unsigned int uint;
using namespace std;


template<typename T>
class Stack {
public:
	Stack();
	//Stack(const Stack<T> & another);
	virtual ~Stack();

	T peek();
	T pop();
	void push(T n);

	void clear();

	bool empty();

	int getTop();

	//friend ostream & operator << (ostream & os, Stack<T,capacity> & s);
private:
	T a[255];
	int top;
};

#endif /* STACK_H_ */
