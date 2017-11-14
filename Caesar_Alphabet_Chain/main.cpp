/*
 * main.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: ouyan
 */

#include <iostream>
using namespace std;

struct node {
	char data;
	node *prior;
	node *next;
};

node * constructDualRing(int n) {
	node *head;
	node *p;
	node *q;

	head = new node;
	head->data = '\0';
	head->prior = NULL;
	head->next = NULL;

	p = head;

	for (int i = 0; i < n; i++) {
		q = new node;
		q->data = 'A' + i;
		q->prior = p;
		p->next = q;
		q->next = NULL;
		p = q;
	}

	p->next = head->next;
	head->next->prior = p;

	node *temp;
	temp = head;
	head = head->next;
	delete temp;

	return head;
}

int main() {
	node *dl;
	dl = constructDualRing(26);

	while (1) {
		node *p;
		p = dl;

		int n;
		cin >> n;
		if (n==0) {
			break;
		}

		if (n >= 0) {
			for (int i = 0; i < n; i++) {
				p = p->next;
			}

			for (int i = 0; i <= 25; i++) {
				cout << p->data << " ";
				p = p->next;
			}
		} else {
			for (int i = 0; i < -n; i++) {
				p = p->prior;
			}
			for (int i = 0; i <= 25; i++) {
				cout << p->data << " ";
				p = p->next;
			}
		}
		cout << endl;
	}

	return 0;
}

