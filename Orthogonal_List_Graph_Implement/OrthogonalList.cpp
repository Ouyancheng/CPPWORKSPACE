/*
 * OrthogonalList.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: ouyan
 */

#include "OrthogonalList.hpp"

OrthogonalList::OrthogonalList() {
	// TODO Auto-generated constructor stub
}

OrthogonalList::~OrthogonalList() {
	// TODO Auto-generated destructor stub
	edge *p=NULL;
	edge *q=NULL;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].firstout;
		if (p==NULL) {
			continue;
		} else {
			while (p->inlink!=NULL) {
				q=p->inlink;
				delete p;
				p=q;
			}
			delete p;
		}
	}
}

void OrthogonalList::addVertex(string name) {
	for (unsigned int i=0;i<a.size();i++) {
		if (a[i].name==name) {
			return;
		}
	}
	vertex v;
	v.name=name;
	v.firstin=NULL;
	v.firstout=NULL;
	a.push_back(v);
}

void OrthogonalList::addEdge(string from, string to) {
	bool foundhead=false;
	bool foundtail=false;
	unsigned int fromindex=0;
	unsigned int toindex=0;

	for (unsigned int i=0;i<a.size();i++) {
		if (a[i].name==to) {
			foundhead=true;
			toindex=i;
		}
		if (a[i].name==from) {
			foundtail=true;
			fromindex=i;
		}
		if (foundhead && foundtail) {
			break;
		}
	}

	if (foundhead==false || foundtail==false) {
		return;
	}

	edge *e;
	e=new edge;

	e->inlink=NULL;
	e->toname=to;
	e->toindex=toindex;

	e->outlink=NULL;
	e->fromname=from;
	e->fromindex=fromindex;

	edge *p;
	p=a[fromindex].firstout;
	if (p==NULL) {
		a[fromindex].firstout=e;
	} else {
		while (p->outlink!=NULL) {
			p=p->outlink;
		}
		p->outlink=e;
	}

	edge *q;
	q=a[toindex].firstin;
	if (q==NULL) {
		a[toindex].firstin=e;
	} else {
		while (q->inlink!=NULL) {
			q=q->inlink;
		}
		q->inlink=e;
	}

	return;
}

void OrthogonalList::showVertex() {
	cout << "Vertices: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		cout << a[i].name << " ";
	}
	cout << endl;
}

void OrthogonalList::showEdge() {
	edge *p;
	p=NULL;
	cout << "NULL pointer: " << p << endl;

	cout << "Edges: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].firstout;
		if (p==NULL) {
			continue;
		} else {
			while (p!=NULL) {
				cout << p << ":";
				cout << "<" << p->fromname << "," << p->toname << "> ";
				cout << p->fromindex << " " << p->toindex << "; ";
				p=p->outlink;
			}
			cout << endl;
		}
	}
}

void OrthogonalList::showEdge_In() {
	edge *p;
	p=NULL;
	cout << "NULL pointer: " << p << endl;

	cout << "Edges: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		p=a[i].firstin;
		//cout << "Vertex: " << a[i].name << endl;
		if (p==NULL) {
			continue;
		} else {
			while (p!=NULL) {
				cout << p << ":";
				cout << "<" << p->fromname << "," << p->toname << "> ";
				cout << p->fromindex << " " << p->toindex << "; ";
				p=p->inlink;
			}
			cout << endl;
		}
	}
}

void OrthogonalList::DepthFirstTraverse_Top(unsigned int index=0) {
	vector<bool> visited;
	visited.reserve(a.size());
	for (unsigned int i=0;i<a.size();i++) {
		visited.push_back(false);
	}

	for (unsigned int i=0;i<a.size();i++) {
		if (visited[i]==false) {
			cout << "Executed once! "<< endl;
			DepthFirstTraverse(i, visited);
		}
	}

	cout << endl;
	for (unsigned int i=0;i<visited.size();i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
}

void OrthogonalList::DepthFirstTraverse(unsigned int index, vector<bool> &visited) {
	cout << a[index].name << " ";
	cout << "Index: " << index << endl;
	visited[index]=true;

	edge *p;
	p=a[index].firstout;

	while (p!=NULL) {
		if (visited[p->toindex]==false) {
			DepthFirstTraverse(p->toindex, visited);
		} else {
			p=p->outlink;
		}
	}
}

int OrthogonalList::getTotalVertices() {
	return a.size();
}
