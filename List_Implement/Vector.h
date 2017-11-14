/*
 * Vector.h
 *
 *  Created on: Jul 21, 2016
 *      Author: ouyan
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;


class Vector {
public:
	Vector();
	Vector(int initSize);
	Vector(const Vector & another);
	virtual ~Vector();

	bool resize(int newSize);
	bool insertElem(int element, int index);
	bool deleteElem(int index);

	void push_back(int element);

	void reverse();

	int operator [] (int index);


	int getSize();
	int getLength();
	bool empty();

	void clear();

    friend ostream & operator << (ostream & os, Vector & v);
private:
	int * a;
	int size;
	int length;
};

#endif /* VECTOR_H_ */
