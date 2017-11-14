/*
 * OrthogonalList.cpp
 *
 *  Created on: Aug 22, 2016
 *      Author: ouyan
 */

#include "OrthogonalList.h"
#include <cstdio>
inline int max(int a, int b) {
	return (a > b) ? a : b;
}
inline int min(int a, int b) {
	return (a < b) ? a : b;
}
inline void println() {
	printf("\n");
}

OrthogonalList::OrthogonalList() {
	// TODO Auto-generated constructor stub

}

OrthogonalList::~OrthogonalList() {
	// TODO Auto-generated destructor stub
	edge *p;
	edge *q;
	for (unsigned int i = 0u; i < a.size(); i++) {
		p = a[i].first;
		if (p == NULL) {
			continue;
		} else {
			while (p->next != NULL) {
				q = p->next;
				delete p;
				p = q;
			}
			delete p;
		}
	}
}

void OrthogonalList::addVertex(const string &name) {
	a.push_back(vertex(name));
}

void OrthogonalList::addEdge(const string &tailname, const string &headname,
		const int &weight) {
	bool foundtail = false;
	bool foundhead = false;
	unsigned int tailindex = 0u;
	unsigned int headindex = 0u;

	for (unsigned int i = 0u; i < a.size(); i++) {
		if (a[i].name == tailname) {
			foundtail = true;
			tailindex = i;
		}
		if (a[i].name == headname) {
			foundhead = true;
			headindex = i;
		}
		if (foundtail && foundhead) {
			break;
		}
	}

	if (!foundtail || !foundhead) {
		return;
	}

	edge *e;
	edge *p;
	e = new edge(tailindex, headindex, weight);
	p = a[tailindex].first;
	if (p == NULL) {
		a[tailindex].first = e;
	} else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = e;
	}
	++a[headindex].indegree;
	++a[tailindex].outdegree;

	p = a[headindex].rfirst;
	if (p == NULL) {
		a[headindex].rfirst = e;
	} else {
		while (p->rnext != NULL) {
			p = p->rnext;
		}
		p->rnext = e;
	}
}

bool OrthogonalList::TopologicalSort(queue<unsigned int> &q1) {
	queue<unsigned int> q;
	unsigned int pushednum = 0u;
	vector<unsigned int> indegree(a.size(), 0u);
	for (unsigned int i = 0; i < a.size(); i++) {
		indegree[i] = a[i].indegree;
	}

	for (unsigned int i = 0; i < a.size(); i++) {
		if (indegree[i] == 0u) {
			q.push(i);
			q1.push(i);
			//cout << a[i].name << " ";
			++pushednum;
		}
	}

	unsigned int tempindex = 0u;
	edge *p = NULL;
	while (!q.empty()) {
		tempindex = q.front();
		q.pop();

		p = a[tempindex].first;
		while (p != NULL) {
			if (--indegree[p->headindex] == 0u) {
				q.push(p->headindex);
				q1.push(p->headindex);
				//cout << a[p->headindex].name << " ";
				++pushednum;
			}
			p = p->next;
		}
	}

	if (pushednum == a.size()) {
		cout << "Successful! " << endl;
		return true;
	} else {
		cout << "Failed! " << endl;
		return false;
	}

}

bool OrthogonalList::TopologicalSort_CPM(stack<unsigned int> &s,
		vector<int> &etv) {
	queue<unsigned int> q;
	etv.clear();
	etv.resize(a.size());

	for (unsigned int i = 0; i < etv.size(); i++) {
		etv[i] = 0;
	}

	unsigned int pushednum = 0u;
	vector<unsigned int> indegree(a.size(), 0u);
	for (unsigned int i = 0; i < a.size(); i++) {
		indegree[i] = a[i].indegree;
	}

	for (unsigned int i = 0; i < a.size(); i++) {
		if (indegree[i] == 0u) {
			q.push(i);
			//etv[i]=0;
			++pushednum;
		}
	}

	unsigned int tempindex = 0u;
	edge *p = NULL;
	while (!q.empty()) {
		tempindex = q.front();
		q.pop();
		s.push(tempindex);

		p = a[tempindex].first;
		while (p != NULL) {
			if (--indegree[p->headindex] == 0u) {
				q.push(p->headindex);
				++pushednum;
			}
			etv[p->headindex] = max(etv[p->headindex],
					etv[p->tailindex] + p->weight);

			p = p->next;
		}
	}

	if (pushednum == a.size()) {
		//cout << "Successful! " << endl;
		return true;
	} else {
		//cout << "Failed! " << endl;
		return false;
	}
}

void OrthogonalList::CriticalPathMethod() {
	stack<unsigned int> s;
	vector<int> etv;
	bool successful = TopologicalSort_CPM(s, etv);
	if (!successful) {
		printf("Circuit exists in the graph!\n");
		return;
	}

	vector<int> ltv(etv.size(), etv.back());

	unsigned int tempindex = 0u;
	edge *p;

	while (!s.empty()) {
		tempindex = s.top();
		s.pop();

		p = a[tempindex].rfirst;

		while (p != NULL) {
			ltv[p->tailindex] = min(ltv[p->tailindex],
					ltv[p->headindex] - p->weight);
			p = p->rnext;
		}
	}

	/*for (unsigned int i=0;i<ltv.size();i++) {
	 cout << ltv[i] << " ";
	 }*/

	//vector<edge> edgev;
	///vector<int> ete;
	///vector<int> lte;
	int ete = 0;
	int lte = 0;

	for (unsigned int i = 0; i < a.size(); i++) {
		p = a[i].first;
		while (p != NULL) {
			//edgev.push_back(*p);
			//ete.push_back(etv[i]);
			//lte.push_back(ltv[p->headindex]-p->weight);
			/*if (ete.back()==lte.back()) {
			 printf("<%s,%s> ", a[p->tailindex].name.c_str(), a[p->headindex].name.c_str());
			 }*/
			ete = etv[p->tailindex];
			lte = ltv[p->headindex] - p->weight;
			if (ete == lte) {
				printf("<%s,%s> ",
						a[p->tailindex].name.c_str(),
						a[p->headindex].name.c_str());
			}
			p = p->next;
		}
	}
	println();
}

void OrthogonalList::print() {
	edge *p;
	for (unsigned int i = 0; i < a.size(); i++) {
		printf("%s: ", a[i].name.c_str());
		p = a[i].first;
		while (p != NULL) {
			printf("<%s,%s,%d> ",
					a[p->tailindex].name.c_str(),
					a[p->headindex].name.c_str(),
					p->weight);
			p = p->next;
		}
		//printf("\n");
		println();
	}
}

void OrthogonalList::rprint() {
	edge *p;
	for (unsigned int i = 0; i < a.size(); i++) {
		printf("%s: ", a[i].name.c_str());
		p = a[i].rfirst;
		while (p != NULL) {
			printf("<%s,%s,%d> ",
					a[p->tailindex].name.c_str(),
					a[p->headindex].name.c_str(),
					p->weight);
			p = p->rnext;
		}
		//printf("\n");
		println();
	}
}

ostream & operator <<(ostream &os, OrthogonalList &ol) {
	edge *p;
	for (unsigned int i = 0; i < ol.a.size(); i++) {
		cout << ol.a[i].name << " Indegree: " << ol.a[i].indegree << " ";
		p = ol.a[i].rfirst;
		while (p != NULL) {
			cout << "<" << ol.a[p->tailindex].name << ","
					<< ol.a[p->headindex].name << "," << p->weight << "> ";
			p = p->rnext;
		}
		cout << endl;
	}

	return os;
}
