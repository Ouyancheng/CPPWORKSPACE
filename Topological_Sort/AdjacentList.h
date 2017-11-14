/*
 * AdjacentList.h
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#ifndef ADJACENTLIST_H_
#define ADJACENTLIST_H_
#include "Queue.h"
#include <vector>
class AdjacentList {
public:
	AdjacentList();
	virtual ~AdjacentList();

	void addVertex(const string &name);

	void addEdge(const string &from, const string &to, const unsigned int &weight=0u);

	void showVertices() const;

	void showEdges() const;

	void TopologicalSort();

private:
	vector<vertex> a;
	unsigned int edgenum;
};

#endif /* ADJACENTLIST_H_ */
