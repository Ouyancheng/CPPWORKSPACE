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
	head->data=0;
	head->next=head;
	p=head;

	for (int i=1;i<=n;i++) {
		q=new node;
		q->data=i;
		q->next=p->next;
		p->next=q;
		p=q;
	}

	node *temp;
	temp=head;
	p->next=head->next;
	head=head->next;
	delete temp;
	cout << "Ring constructed! " << endl;

	return head;
}


int main() {
	int n;
	cin >> n;

	node *l;
	l=constructRing(n);

	node *p;
	p=l;

	cout << "Matrix: " << endl;
	for (int i=1;i<=n;i++) {
		p=l;
		for (int k=1;k<i;k++) {
			p=p->next;
		}
		for (int j=1;j<=n;j++) {

			cout << p->data << " ";
			p=p->next;
		}
		cout << endl;
	}

	p=l;
	cout << "Ring: " << endl;
	while (p->next!=l) {
		cout << p->data << " ";
		p=p->next;
	}
	cout << p->data << endl;

	return 0;
}

