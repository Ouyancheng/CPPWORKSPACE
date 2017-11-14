/*
 * Vector.h
 *
 *  Created on: Aug 31, 2016
 *      Author: ouyan
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include <iostream>
template<class T>
class Vector {
public:
	Vector(unsigned int _capacity = 128) {
		a=new T[_capacity];
		vsize=0u;
		vcapacity=_capacity;
	}
	virtual ~Vector() {
		if (a!=nullptr) {
			delete a;
		}
	}

	void push_back(T element) {
		if (vsize==vcapacity) {
			T *p;
			p=new T[2*vcapacity];
			vcapacity*=2;
			for (unsigned int i=0;i<vsize;i++) {
				p[i]=a[i];
			}
			delete a;
			a=p;
			a[vsize]=element;
			++vsize;
		} else {
			a[vsize]=element;
			++vsize;
		}
	}

	T back() {
		return a[vsize-1];
	}


	T pop_back() {
		T result=a[vsize-1];
		--vsize;
		return result;
	}

	T & operator [](unsigned int index) {
		return a[index];
	}

	bool empty() {
		if (vsize==0u) {
			return true;
		} else {
			return false;
		}
	}

	unsigned int size() {
		return vsize;
	}
	unsigned int capacity() {
		return vcapacity;
	}

	void clear() {
		vsize=0;
	}

private:
	T *a;
	unsigned int vsize;
	unsigned int vcapacity;
};

#endif /* VECTOR_HPP_ */
