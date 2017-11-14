/*
 * Linklist_construct.h
 *
 *  Created on: Jul 27, 2016
 *      Author: ouyan
 */

#ifndef LINKLIST_CONSTRUCT_H_
#define LINKLIST_CONSTRUCT_H_
#include <iostream>

struct node {
	int data;
	node *next;
};


node * constructLine(int n) {
	node *head;
	node *p;
	node *q;
	p=new node;
	p->data=0;
	head=p;
	for (int i=0;i<n;i++) {
		q=new node;
		q->data=i;
		p->next=q;
		p=q;
	}
	p->next=NULL;
	return head;
}

node * constructRing(int n) {
	node *head;
	node *p;
	node *q;
	p=new node;
	p->next=p;
	head=p;
	for (int i=0;i<n;i++) {
		q=new node;
		q->data=i;
		q->next=p->next;
		p->next=q;
	}
	return head;
}

#endif /* LINKLIST_CONSTRUCT_H_ */
