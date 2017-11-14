/*
 * main.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: ouyan
 */

#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

node * constructRing(int n) {
	node *head;

	node *p;
	node *q;

	head=new node;
	head->data=-1;
	head->next=head;
	p=head;

	for (int i=0;i<n;i++) {
		q=new node;
		q->data=0;
		q->next=p->next;
		p->next=q;
		p=q;
	}

	node *temp;
	temp=head;
	head=head->next;
	p->next=head;
	delete temp;

	cout << "Ring constructed! " << endl;
	return head;
}

int main() {
	node *l;
	l=constructRing(13);

	//int count=1;
	node *p;
	p=l;

	for (int i=1;i<=13;i++) {
		for (int j=1;j<=i;j++) {
			cout << "Step" << j << endl;
			p=p->next;
			while (p->data!=0) {
				p=p->next;
			}

		}
		p->data=i;
		cout << "Parsed " << i << endl;
	}

	node *q;
	q=l->next;
	while (q->next!=l->next) {
		cout << q->data << " ";
		q=q->next;
	}
	cout << q->data << endl;

	return 0;
}
