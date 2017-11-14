/*
 * OrthogonalList.h
 *
 *  Created on: Aug 22, 2016
 *      Author: ouyan
 */

#ifndef ORTHOGONALLIST_H_
#define ORTHOGONALLIST_H_
#include "Node.h"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class OrthogonalList {
public:
	OrthogonalList();
	virtual ~OrthogonalList();

	void addVertex(const string &name);

	void addEdge(const string &tailname, const string &headname,
			const int &weight);

	bool TopologicalSort(queue<unsigned int> &q);

	void CriticalPathMethod();

	void print();
	void rprint();

	friend ostream & operator <<(ostream &os, OrthogonalList &al);

private:
	vector<vertex> a;

	bool TopologicalSort_CPM(stack<unsigned int> &s, vector<int> &etv);
};

#endif /* ORTHOGONALLIST_H_ */
