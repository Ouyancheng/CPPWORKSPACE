/*
 * AdjacentList.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <iostream>
AdjacentList::AdjacentList() {
	// TODO Auto-generated constructor stub

}

AdjacentList::~AdjacentList() {
	// TODO Auto-generated destructor stub
}

void AdjacentList::addVertex(string name) {
	for (unsigned int i=0;i<a.size();i++) {
		if (a[i].name==name) {
			return;
		}
	}

	vertex v;
	v.name=name;
	v.outdegree=0;
	v.first=NULL;

	a.push_back(v);

}

void AdjacentList::addEdge(string from, string to, int weight) {
	bool foundfrom=false;
	bool foundto=false;
	int fromindex=0;
	int toindex=0;
	for (unsigned int i=0;i<a.size();i++) {
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

	edge *e;
	e=new edge;
	e->headindex=toindex;
	e->tailindex=fromindex;
	e->weight=weight;
	e->next=NULL;

	edge *p;
	p=a[fromindex].first;
	if (p==NULL) {
		a[fromindex].first=e;
	} else {
		while (p->next!=NULL) {
			p=p->next;
		}
		p->next=e;
	}
	++a[fromindex].outdegree;

	e=new edge;
	e->headindex=fromindex;
	e->tailindex=toindex;
	e->weight=weight;
	e->next=NULL;

	p=a[toindex].first;
	if (p==NULL) {
		a[toindex].first=e;
	} else {
		while (p->next!=NULL) {
			p=p->next;
		}
		p->next=e;
	}
	++a[toindex].outdegree;

}

void AdjacentList::showVertex() {
	cout << "Vertices: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		cout << a[i].name << " ";
	}
	cout << endl;
}

void AdjacentList::showEdge() {
	cout << "Edges: " << endl;
	edge *p;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].first;
		while (p!=NULL) {
			if ((unsigned)p->headindex>=i) {
				cout << "(" << a[i].name << "," << a[p->headindex].name << ","
					<< p->weight << ") ";
			}
			p=p->next;
		}
		cout << endl;
	}
}

void AdjacentList::PrimAlgorithm(int i) {
	lownode maxln;
	maxln.fromindex=0;
	maxln.weight=INT_MAX;
	vector<lownode> low(a.size(), maxln);
	vector<bool> visited(a.size(), false);

	unsigned visitednum=0;
	edge *p=NULL;
	int index=i;
	int fromindex=0;
	int currentweight=0;

	int totalweight=0;

	cout << "Minimum Spanning Tree: " << endl;

	while (visitednum<a.size()) {
		visited[index]=true;
		if (visitednum>0) {
			cout << "(" << a[fromindex].name << "," << a[index].name << ","
					<< currentweight << ") ";
			totalweight+=currentweight;
		}
		++visitednum;

		p=a[index].first;
		while (p!=NULL) {
			if (!visited[p->headindex] && low[p->headindex].weight>p->weight) {
				low[p->headindex].weight=p->weight;
				low[p->headindex].fromindex=index;
			}
			p=p->next;
		}


		int lowestweight=INT_MAX;
		for (unsigned i=0;i<low.size();i++) {
			if (!visited[i] && low[i].weight<lowestweight) {
				lowestweight=low[i].weight;
				index=i;
				fromindex=low[i].fromindex;
			}
		}
		currentweight=lowestweight;

	}

	cout << endl << "Total weight: " << totalweight << endl;
}

