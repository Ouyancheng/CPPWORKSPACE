/*
 * AdjacentList.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <iostream>
#include "Queue.h"
using namespace std;
AdjacentList::AdjacentList() {
	// TODO Auto-generated constructor stub
}

AdjacentList::~AdjacentList() {
	// TODO Auto-generated destructor stub
	edge *p;
	edge *q;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].firstout;
		if (p==NULL) {
			continue;
		} else {
			while (p->next!=NULL) {
				q=p->next;
				delete p;
				p=q;
			}
			delete p;
		}
	}
}

void AdjacentList::addVertex(string name) {
	vertex v;
	v.firstout=NULL;
	v.name=name;
	v.outdegree=0;
	a.push_back(v);
}

void AdjacentList::addEdge(string from, string to) {
	bool foundfrom=false;
	bool foundto=false;
	int fromindex=0;
	int toindex=0;
	for (unsigned int i=0;i<a.size();i++) {
		if (foundfrom && foundto) {
			break;
		}
		if (a[i].name==from) {
			foundfrom=true;
			fromindex=i;
		}
		if (a[i].name==to) {
			foundto=true;
			toindex=i;
		}
	}
	if (!foundfrom || !foundto) {
		return;
	}

	edge *e;
	e=new edge;
	e->headindex=toindex;
	e->headname=to;
	e->next=NULL;

	edge *p;
	p=a[fromindex].firstout;
	++a[fromindex].outdegree;
	if (p==NULL) {
		a[fromindex].firstout=e;
	} else {
		while (p->next!=NULL) {
			p=p->next;
		}
		p->next=e;
	}
}

void AdjacentList::showVertex() {
	cout << "Vertices: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		cout << "Name: " << a[i].name << " Out Degree: " << a[i].outdegree << endl;
	}
	cout << endl;
}

void AdjacentList::showEdge() {
	cout << "Edges: " << endl;
	edge *p;
	for (unsigned int i=0;i<a.size();i++) {
		cout << a[i].name << ": ";
		p=a[i].firstout;
		while (p!=NULL) {
			cout << "<" << a[i].name << "," << p->headname << "> ";
			p=p->next;
		}
		cout << endl;
	}
}

void AdjacentList::BreadthFirstTraverse(int index) {
	vector<bool> visited(a.size(), false);
	Queue q;
	q.push_back(a[index].name, index);
	visited[index]=true;

	while (q.getLength()>0) {
		int i;
		i=q.pop_front();
		cout << a[i].name << " ";

		edge *p;
		p=a[i].firstout;
		while (p!=NULL) {
			if (!visited[p->headindex]) {
				q.push_back(p->headname, p->headindex);
				visited[p->headindex]=true;
			}
			p=p->next;
		}
	}
}

void AdjacentList::DepthFirstTraverse(int index) {
	vector<bool> visited(a.size(), false);
	DepthFirstTraverseCore(index, visited);
}

void AdjacentList::DepthFirstTraverseCore(int index, vector<bool> &visited) {
	visited[index]=true;
	cout << a[index].name << " ";

	edge *p;
	p=a[index].firstout;
	if (p==NULL) {
		return;
	}

	while (p!=NULL) {
		if (visited[p->headindex]==false) {
			DepthFirstTraverseCore(p->headindex, visited);
		}
		p=p->next;
	}
}

