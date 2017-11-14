/*
 * main.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: ouyan
 */

#include "Linklist_construct.h"
#include <iostream>
using namespace std;

void JudgeRingpq(node* l1) {
	node* p;
	int pstep = 0;
	int qstep;
	node* q;
	p = l1;
	while (p->next != NULL) {
		p = p->next;
		++pstep;
		q = l1;
		qstep = 0;
		while (q != p && q->next != NULL) {
			q = q->next;
			++qstep;
		}
		if (q == p && qstep != pstep) {
			cout << "Is ring. " << endl;
			break;
		}
	}
	if (p->next == NULL) {
		cout << "Is not ring. " << endl;
	}
}

void JudgeRingFSpointer(node *l2) {
	node *p;
	node *q;
	p=l2;
	q=l2;

	while (p->next!=NULL) {
		if (p->next->next==NULL) {
			/*p=p->next;
			q=q->next;
			if (p==q) {
				cout << "Is ring. " << endl;
				break;
			}*/
			cout << "Is not ring. " << endl;
			return;
		} else {
			p=p->next->next;
			q=q->next;
			if (p==q) {
				cout << "Is ring" << endl;
				break;
			}
		}
	}

	if (p!=q) {
		cout << "Is not ring. " << endl;
	}
}

int main() {
	node *l1;
	l1=constructLine(10);

	JudgeRingpq(l1);

	node *l2;
	l2=constructRing(10);
	JudgeRingpq(l2);

	JudgeRingFSpointer(l1);
	JudgeRingFSpointer(l2);

	return 0;
}


