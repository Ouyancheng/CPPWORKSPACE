/*
 * List_Struct.h
 *
 *  Created on: Jul 20, 2016
 *      Author: ouyan
 */

#ifndef LIST_STRUCT_H_
#define LIST_STRUCT_H_

#include <stdio.h>
#include <stdlib.h>


/*#define false 0
#define true 1
typedef short int bool;*/

struct List {
	int * a;
	int length;
	int size;
};

bool InitList(int n, struct List * l) {
	if (n<=0) {
		return false;
	}

	if (l->a!=NULL) {
		free(l->a);
		l->a=NULL;
	}
	l->a=(int *)malloc(n*sizeof(int));
	l->length=0;
	l->size=n;
	return true;
}

int getElem(int index, struct List * l) {
	return l->a[index];
}

bool emptyList(struct List * l) {
	if (l->length==0) {
		return true;
	} else {
		return false;
	}
}

bool nullList(struct List * l) {
	if (l->a==NULL) {
		return true;
	} else {
		return false;
	}
}

bool insertElem(int element, int index, struct List * l) {
	int i;
	int * p;
	if ((index<0)||(index>l->length)) {
		return false;
	}
	if (l->length==l->size) {
		p=(int *)malloc(2*(l->size)*sizeof(int));
		for (i=0;i<=index;i++) {
			p[i]=l->a[i];
		}

		p[index]=element;

		for (i=index+1;i<=l->length;i++) {
			p[i]=l->a[i-1];
		}

		free(l->a);
		l->a=NULL;

		++(l->length);
		l->size*=2;
		l->a=p;

	} else {
		for (i=l->length-1;i>=index;i--) {
			l->a[i+1]=l->a[i];
		}
		l->a[index]=element;
		l->length++;
	}
	return true;
}

bool deleteElem(int index, struct List * l) {
	int i;
	if ((index<0)||(index>=l->length)) {
		return false;
	}
	for (i=index+1;i<=l->length-1;i++) {
		l->a[i-1]=l->a[i];
	}
	--(l->length);
	return true;
}

void push_back(int element, struct List * l) {
	int i;
	int * p;
	if (l->length==l->size) {
		p=(int *)malloc(2*(l->size)*sizeof(int));
		for (i=0;i<l->length;i++) {
			p[i]=l->a[i];
		}
		p[l->length]=element;
		l->size*=2;
		++(l->length);
		free(l->a);
		l->a=NULL;
		l->a=p;
	} else {
		l->a[(l->length)]=element;
		++(l->length);
	}
}

void clearList(struct List * l) {
	l->length=0;
}

void resetList(struct List * l) {
	l->length=0;
	l->size=0;
	if (l->a!=NULL) {
		free(l->a);
		l->a=NULL;
	}
}




#endif /* LIST_STRUCT_H_ */
