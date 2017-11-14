/*
 * StaticLinklist.h
 *
 *  Created on: Jul 24, 2016
 *      Author: ouyan
 */

#ifndef STATICLINKLIST_H_
#define STATICLINKLIST_H_
#include "Node.h"
#include <iostream>
using namespace std;


class Static_Linklist {
public:
	Static_Linklist();
	Static_Linklist(int n);
	Static_Linklist(const Static_Linklist &another);
	virtual ~Static_Linklist();

	int malloc_space();

	bool push_back(int element);

	bool insertElem(int index, int element);
	bool deleteElem(int index);

	int & getElem(int index);

	friend ostream & operator <<(ostream &os, Static_Linklist &l);

	void showArray();

private:
	node *a;
	int length;
	int size;
};

#endif /* STATICLINKLIST_H_ */
