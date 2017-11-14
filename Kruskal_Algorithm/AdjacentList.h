/*
 * AdjacentList.h
 *
 *  Created on: Aug 17, 2016
 *      Author: ouyan
 */

#ifndef ADJACENTLIST_H_
#define ADJACENTLIST_H_
#include <vector>
#include <iostream>
#include "Node.h"



class AdjacentList {
public:
	AdjacentList();
	virtual ~AdjacentList();

	void addVertex(string name);

	void addEdge(string from, string to, int weight);

	void KruskalAlgorithm();

	friend ostream &operator <<(ostream &os, AdjacentList &al);

private:
	vector<vertex> a;

};

#endif /* ADJACENTLIST_H_ */
