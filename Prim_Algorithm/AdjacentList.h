/*
 * AdjacentList.h
 *
 *  Created on: Aug 16, 2016
 *      Author: ouyan
 */

#ifndef ADJACENTLIST_H_
#define ADJACENTLIST_H_
#include <vector>
#include <string>
#include <cstddef>
#include "Node.h"

using namespace std;
class AdjacentList {
public:
	AdjacentList();
	virtual ~AdjacentList();

	void addVertex(string name);

	void addEdge(string from, string to, int weight);

	void showVertex();

	void showEdge();

	void PrimAlgorithm(int index);

private:
	vector<vertex> a;
};

#endif /* ADJACENTLIST_H_ */
