/*
 * main.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: ouyan
 */

#include <iostream>
using namespace std;

struct node {
	int number;
	node *next;
};

void constructLinklist(int n, node *head) {
	node *p;
	p=head;

	node *q;

	for (int i=1;i<=n;i++) {
		q=new node;
		q->number=i;
		q->next=head;
		p->next=q;
		p=q;
	}

	p->next=head->next;

}

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;

	node *head=new node;
	constructLinklist(n,head);

	node *free;
	free=head;
	head=head->next;
	delete free;

	node *p;
	p=head;

	node *q=head;
	while (q->next!=head) {
		q=q->next;
	}

	int num=0;

	while (p->next!=p) {
		num++;
		if (num==m) {
			cout << p->number << " ";
			q->next=p->next;
			node *free;
			free=p;
			p=p->next;
			delete free;
			num=1;

		}
		p=p->next;
		q=q->next;
	}
	cout << p->number << endl;
	delete p;

	return 0;
}

