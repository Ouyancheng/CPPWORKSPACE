#include <stdio.h>

struct node
{
	int data;
	node * next;
};


int getElem(int index, LinkList * l) {
	node * p;
	p=l->next;
	int j=0;
	while (p && j<index) {
		p=p->next;
		++j;
	}
	if ((p==NULL)||(j>=index)) {
		return 0;
	}

	return p->data;
}



int deleteElem(int index, LinkList * l) {
	int j=0;
	node * p = l;
	while (p && j<index) {
		p=p->next;
		j++;
	}
	if ((!p)||(j>=index)) {
		return 0;
	}
	node * q=p->next;
	p->next=p->next->next;
	free(q);
	return 1;
}

int insertElem(int element, int index, LinkList * l) {
	int j=0;
	node * p=l;
	while (p && j<index) {
		p=p->next;
		j++;
	}
	if ((!p)||(j>=index)) {
		return 0;
	}
	node * q;
	q=new node;
	q->data=element;
	q->next=p->next;
	p->next=q;
	return 1;
}