/*
 * Stack.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: ouyan
 */

#include "Stack.h"
#include "Element.h"

template<typename T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	top=-1;
}

/*template<typename T>
Stack<T>::Stack(const Stack<T> & another) {
	top=another.top;
	for (int i=0;i<=top;i++) {
		a[i]=another.a[i];
	}
}*/

template<typename T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
}

template<typename T>
T Stack<T>::peek() {
	return a[top];
}

template<typename T>
T Stack<T>::pop() {
	T temp;
	temp=a[top];
	top--;
	return temp;
}

template<typename T>
void Stack<T>::push(T n) {
	if (top==254) {
		return;
	} else {
		top++;
		a[top]=n;
	}
}

template<typename T>
void Stack<T>::clear() {
	top=-1;
}

template<typename T>
bool Stack<T>::empty() {
	if (top==-1) {
		return true;
	} else {
		return false;
	}
}

template<typename T>
int Stack<T>::getTop() {
	return top;
}

/*template<typename T>
ostream & operator << (ostream & os, Stack<T> s) {
	int i=s.top;
	while (i!=-1) {
		os << s.a[i] << " ";
		i--;
	}
	return os;
}*/

template class Stack<char>;
template class Stack<element>;
template class Stack<int>;
