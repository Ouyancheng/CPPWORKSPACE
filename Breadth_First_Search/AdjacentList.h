/*
 * AdjacentList.h
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#ifndef ADJACENTLIST_H_
#define ADJACENTLIST_H_
#include <vector>
#include <string>
#include "ALNode.h"
using namespace std;


class AdjacentList {
public:
	AdjacentList();
	virtual ~AdjacentList();

	void addVertex(string name);

	void addEdge(string from, string to);

	void showVertex();

	void showEdge();

	void BreadthFirstTraverse(int index);

	void DepthFirstTraverse(int index);

private:
	std::vector<vertex> a;

	void DepthFirstTraverseCore(int index, vector<bool> &visited);
};

#endif /* ADJACENTLIST_H_ */
