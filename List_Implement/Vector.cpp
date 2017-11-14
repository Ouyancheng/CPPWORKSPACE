/*
 * Vector.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: ouyan
 */

#include "Vector.h"
using namespace std;

Vector::Vector() {
	// TODO Auto-generated constructor stub
	a=new int[10];
	size=10;
	length=0;
}

Vector::Vector(int initSize) {
	a=new int[initSize];
	size=initSize;
	length=0;
}

Vector::Vector(const Vector & another) {
	size=another.size;
	length=another.length;
	a=new int[size];
	for (int i=0;i<=another.length-1;i++) {
		a[i]=another.a[i];
	}
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
	if (a!=NULL) {
		delete []a;
		a=NULL;
	}
}

bool Vector::resize(int newSize) {
	if (newSize<=0) {
		return 0;
	}
	if (length>newSize) {
		int * p;
		p=new int[newSize];
		for (int i=0;i<=newSize-1;i++) {
			p[i]=a[i];
		}
		length=newSize;
		size=newSize;
		delete [] a;
		a=p;
	} else {
		int * p;
		p=new int[newSize];
		for (int i=0;i<=length-1;i++) {
			p[i]=a[i];
		}
		size=newSize;
		delete [] a;
		a=p;
	}
	return 1;
}

bool Vector::insertElem(int element, int index) {
	if ((index<0)||(index>length)) {
		return 0;
	} else {
		if (length>=size) {
			int * p;
			p=new int[2*size];
			for (int i=0;i<=index-1;i++) {
				p[i]=a[i];
			}
			p[index]=element;
			for (int i=index+1;i<=length;i++) {
				p[i]=a[i-1];
			}
			delete [] a;
			a=p;
			size*=2;
			length++;
		} else {
			for (int i=length-1;i>=index;i--) {
				a[i+1]=a[i];
			}
			a[index]=element;
			length++;
		}
		return 1;
	}
}

bool Vector::deleteElem(int index) {
	if ((index<0)||(index>=length)) {
		return 0;
	} else {
		for (int i=index;i<=length-2;i++) {
			a[i]=a[i+1];
		}
		length--;
		return 1;
	}
}

void Vector::push_back(int element) {
	insertElem(element, length);
}

void Vector::reverse() {
	int halfLength=length/2;
	int temp;
	for (int i=0;i<=halfLength-1;i++) {
		temp=a[i];
		a[i]=a[length-1-i];
		a[length-1-i]=temp;
	}
	return;
}

int Vector::operator [](int index) {
	if ((index<0)||(index>=length)) {
		return 0;
	} else {
		return a[index];
	}
}

int Vector::getLength() {
	return length;
}

int Vector::getSize() {
	return size;
}

bool Vector::empty() {
	if (length==0) {
		return 1;
	} else {
		return 0;
	}
}


void Vector::clear() {
	length=0;
}

ostream & operator <<(ostream & os, Vector & v) {
	os << "Element(s): " << endl;
	for (int i=0;i<=v.length-1;i++) {
		os << v.a[i] << " ";
	}
	os << endl;
	os << "Size:   " << v.size << endl;
	os << "Length: " << v.length << endl;
	return os;
}
