/*
 * AdjacentList.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <algorithm>
AdjacentList::AdjacentList(): a() {
	// TODO Auto-generated constructor stub

}

AdjacentList::~AdjacentList() {
	// TODO Auto-generated destructor stub
	edge *p;
	edge *q;
	for (unsigned i=0;i<a.size();i++) {
		p=a[i].first;
		if (p==NULL) {
			continue;
		} else {
			p=a[i].first;
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
	for (unsigned i=0;i<a.size();i++) {
		if (a[i].name==name) {
			return;
		}
	}

	vertex v;
	v.name=name;
	v.first=NULL;
	v.degree=0u;

	a.push_back(v);
}

void AdjacentList::addEdge(string from, string to, int weight) {
	bool foundfrom=false;
	bool foundto=false;
	unsigned fromindex=0;
	unsigned toindex=0;

	for (unsigned i=0;i<a.size();i++) {
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
	e->fromindex=fromindex;
	e->toindex=toindex;
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

	e=new edge;
	e->fromindex=toindex;
	e->toindex=fromindex;
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
}

void AdjacentList::KruskalAlgorithm() {
	vector<edge> edgev;
	vector<unsigned> vset(a.size());

	edge *p;
	for (unsigned i=0;i<a.size();i++) {
		vset[i]=i;

		p=a[i].first;
		while (p!=NULL) {
			if (p->fromindex < p->toindex) {
				edgev.push_back(*p);
			}
			p=p->next;
		}
	}

	sort(edgev.begin(), edgev.end());


	//unsigned totaledge=edgev.size();

	unsigned edgevindex=0;
	unsigned addededge=0;

	cout << "Minimal Spanning Tree: " << endl;
	while (addededge < a.size()-1) {
		unsigned setnum1=vset[edgev[edgevindex].fromindex];
		unsigned setnum2=vset[edgev[edgevindex].toindex];

		if (setnum1 != setnum2) {
			cout << "(" << a[edgev[edgevindex].fromindex].name << ","
					<< a[edgev[edgevindex].toindex].name << ","
					<< edgev[edgevindex].weight << ") ";

			for (unsigned i=0;i<vset.size();i++) {
				if (vset[i]==setnum2) {
					vset[i]=setnum1;
				}
			}
			++addededge;
		}
		++edgevindex;
	}

}

ostream &operator <<(ostream &os, AdjacentList &al) {
	edge *p;
	for (unsigned i=0;i<al.a.size();i++) {
		os << al.a[i].name << ": ";
		p=al.a[i].first;
		while (p!=NULL) {
			if (p->fromindex <= p->toindex) {
				os << "(" << al.a[p->fromindex].name << ","
						<< al.a[p->toindex].name << ","
						<< p->weight << ") ";
			}
			p=p->next;
		}
		os << endl;
	}
	return os;
}
