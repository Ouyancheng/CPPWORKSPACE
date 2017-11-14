/*
 * StaticLinklist.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: ouyan
 */

#include "StaticLinklist.h"

Static_Linklist::Static_Linklist() {
	// TODO Auto-generated constructor stub
	a=new node[12];
	a[0].cur=1;
	a[0].data=0;
	a[11].cur=0;
	a[11].data=0;
	size=12;
	length=0;
	for (int i=1;i<=10;i++) {
		a[i].cur=i+1;
		a[i].data=0;
	}
}

Static_Linklist::Static_Linklist(int n) {
	a=new node[n+2];
	a[0].cur=1;
	a[0].data=0;
	a[n+1].cur=0;        //n+1==n+2-1;
	a[n+1].data=0;
	size=n+2;
	length=0;
	for (int i=1;i<=size-2;i++) {
		a[i].cur=i+1;
		a[i].data=0;
	}
}

Static_Linklist::Static_Linklist(const Static_Linklist &another) {
	if (a!=NULL) {
		delete [] a;
		a=NULL;
	}
	size=another.size;
	length=another.length;
	a=new node[size];
	for (int i=0;i<=size-1;i++) {
		a[i]=another.a[i];
	}
}

Static_Linklist::~Static_Linklist() {
	// TODO Auto-generated destructor stub
	delete [] a;
	a=NULL;
}

int Static_Linklist::malloc_space() {
	if (length==size-2) {
		return 0;
	}
	int i;
	i=a[0].cur;
	a[0].cur=a[i].cur;
	cout << "Malloced: " << i << endl;
	return i;
}

bool Static_Linklist::push_back(int element) {
	int space;
	space=malloc_space();
	if (space==0) {
		return false;
	}

	int i=size-1;

	while (a[i].cur!=0) {
		i=a[i].cur;
	}
	a[i].cur=space;
	a[space].cur=0;
	a[space].data=element;
	++length;
	return 1;
}

bool Static_Linklist::insertElem(int index, int element) {
	if ((index<0)||(index>length)) {
		return false;
	}

	int i=size-1;

	//This for loop can take i to the element just before the index element.
	for (int j=0;j<index;j++) {
		i=a[i].cur;
	}

	if (a[i].cur==0) {
		return push_back(element);
	}

	int space;
	space=malloc_space();
	if (space==0) {
		return false;
	}

	int i2=a[i].cur;

	a[i].cur=space;
	a[space].data=element;
	a[space].cur=i2;
	++length;
	return true;
}

bool Static_Linklist::deleteElem(int index) {
	if ((index<0)||(index>=length)) {
		return false;
	}

	int i;
	i=size-1;

	//The for loop can take i to the element just before the index element.
	for (int j=0;j<index;j++) {
		i=a[i].cur;
	}

	//i2 is the element to be deleted.
	int i2;
	i2=a[i].cur;

	a[i].cur=a[i2].cur;

	//Refresh the empty space link list. There are 2 ways.
	//#1 way to refresh the empty space link list.
	/*int free1;
	free1=0;
	//The while loop takes free1 to the empty element whose cursor is just less than i2.
	while (a[free1].cur<i2) {
		free1=a[free1].cur;
	}
	a[i2].cur=a[free1].cur;
	a[free1].cur=i2;*/

	//#2 way to refresh the empty space link list.
	a[i2].cur=a[0].cur;
	a[0].cur=i2;

	--length;

	return 1;
}

int & Static_Linklist::getElem(int index) {
	if ((index<0)||(index>=length)) {
		return a[size-1].data;
	}
	int i;
	i=size-1;


	for (int j=0;j<=index;j++) {
		i=a[i].cur;
	}

	return a[i].data;

}

ostream & operator <<(ostream &os, Static_Linklist &l) {
	os << "Size:   " << l.size << endl;
	os << "Length: " << l.length << endl;
	os << "Element(s): " << endl;
	int i=l.size-1;
	while (l.a[i].cur!=0) {
		i=l.a[i].cur;
		os << l.a[i].data << " ";
	}

	return os;
}

void Static_Linklist::showArray() {
	for (int i=0;i<=size-1;i++) {
		cout << i << " Cursor: " << a[i].cur << " Data: " << a[i].data << endl;
	}
	cout << endl;
}
