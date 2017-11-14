/*
 * AdjacentList.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"

AdjacentList::AdjacentList() {
	// TODO Auto-generated constructor stub
	edgenum=0;
}

AdjacentList::~AdjacentList() {
	// TODO Auto-generated destructor stub
	edge *p;
	edge *q;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].first;
		if (p==NULL) {
			continue;
		}
		while (p->next!=NULL) {
			q=p->next;
			delete p;
			p=q;
		}
		delete p;
	}
}

void AdjacentList::addVertex(string name) {
	for (unsigned int i=0;i<a.size();i++) {
		if (a[i].name==name) {
			return;
		}
	}

	vertex v;
	v.name=name;
	v.first=NULL;

	a.push_back(v);
}

void AdjacentList::addEdge(string from, string to, unsigned int weight) {
	bool foundfrom=false;
	bool foundto=false;
	unsigned int fromindex=0;
	unsigned int toindex=0;

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

	/*if (fromindex != toindex) {
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
	}*/
}

void AdjacentList::DijkstraAlgorithm(unsigned int begin) {
	vector<lownode> low(a.size(), lownode());
	low[begin].length=0;

	unsigned int index=begin;

	unsigned int visitednum=0;

	while (visitednum < low.size()) {
		low[index].visited=true;
		++visitednum;

		edge *p;
		p=a[index].first;
		while (p!=NULL) {
			if (low[p->headindex].length > (low[index].length+p->weight)) {
				low[p->headindex].length = (low[index].length + p->weight);
				low[p->headindex].fromindex=index;
			}
			p=p->next;
		}

		unsigned int shortest=INT_MAX;
		for (unsigned int i=0;i<low.size();i++) {
			if (low[i].visited==false && low[i].length<shortest) {
				shortest=low[i].length;
				index=i;
			}
		}
		cout << "Next index: " << index << endl;
	}

	for (unsigned int i=0;i<low.size();i++) {
		cout << low[i].length << " ";
	}
	cout << endl;
}

ostream &operator <<(ostream &os, AdjacentList &al) {
	edge *p;
	for (unsigned i=0;i<al.a.size();i++) {
		os << al.a[i].name << ": ";
		p=al.a[i].first;
		while (p!=NULL) {
			if (p->tailindex <= p->headindex) {
				os << "(" << al.a[p->tailindex].name << ","
						<< al.a[p->headindex].name << ","
						<< p->weight << ") ";
			}
			p=p->next;
		}
		os << endl;
	}

	return os;
}

