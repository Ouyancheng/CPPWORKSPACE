/*
 * AdjacentList.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <iostream>
AdjacentList::AdjacentList() {
	// TODO Auto-generated constructor stub
	edgenum=0u;
}

AdjacentList::~AdjacentList() {
	// TODO Auto-generated destructor stub
	edge *p;
	edge *q;
	for (unsigned int i=0u;i<a.size();i++) {
		p=a[i].first;
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

void AdjacentList::addVertex(const string &name) {
	a.push_back(vertex(name));
}

void AdjacentList::addEdge(
		const string &from,
		const string &to,
		const unsigned int &weight) {
	bool foundfrom=false;
	bool foundto=false;
	unsigned int fromindex=0u;
	unsigned int toindex=0u;

	for (unsigned int i=0u;i<a.size();i++) {
		if (a[i].name==from) {
			foundfrom=true;
			fromindex=i;
		}
		if (a[i].name==to) {
			foundto=true;
			toindex=i;
		}
		if (foundfrom && foundto) {
			break;
		}
	}

	if (!foundfrom || !foundto) {
		return;
	}

	++a[toindex].indegree;

	edge *p;
	p=a[fromindex].first;
	if (p==NULL) {
		a[fromindex].first=new edge(fromindex, toindex, weight);
	} else {
		while (p->next!=NULL) {
			p=p->next;
		}
		p->next=new edge(fromindex, toindex, weight);
	}
	++edgenum;
}

void AdjacentList::showVertices() const {
	cout << "Vertices: " << endl;
	for (unsigned int i=0u;i<a.size();i++) {
		cout << a[i].name << " ";
	}
	cout << endl;
}

void AdjacentList::showEdges() const {
	cout << "Number of edges: " << edgenum << endl;
	cout << "Edges: " << endl;
	edge *p;
	for (unsigned int i=0u;i<a.size();i++) {
		p=a[i].first;
		while (p!=NULL) {
			cout << "<" << a[p->fromindex].name << ","
					<< a[p->toindex].name << "> ";
			p=p->next;
		}
		if (a[i].first!=NULL) {
			cout << endl;
		}
	}
}

void AdjacentList::TopologicalSort() {
	Queue q;
	unsigned int pushednum=0u;
	for (unsigned int i=0u;i<a.size();i++) {
		if (a[i].indegree==0u) {
			q.push_back(i);
			++pushednum;
		}
	}

	unsigned int index=0u;
	edge *p;
	while (q.getLength()!=0u) {
		index=q.pop_front().index;
		cout << a[index].name << "->";

		p=a[index].first;
		while (p!=NULL) {
			if (a[p->toindex].indegree>0u) {
				--a[p->toindex].indegree;
				if (a[p->toindex].indegree==0u) {
					q.push_back(p->toindex);
					++pushednum;
				}
			}
			p=p->next;
		}

	}
	if (pushednum<a.size()) {
		cout << "Failed! " << endl;
	} else {
		cout << "Successful! " << endl;
	}
}
