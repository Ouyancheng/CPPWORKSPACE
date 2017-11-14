/*
 * OrthogonalList.h
 *
 *  Created on: Aug 12, 2016
 *      Author: ouyan
 */

#ifndef ORTHOGONALLIST_HPP_
#define ORTHOGONALLIST_HPP_
#include "Node.hpp"
#include <vector>
#include <iostream>
#include <string>


using namespace std;

class OrthogonalList {
public:
	OrthogonalList();
	virtual ~OrthogonalList();

	void addVertex(string name);

	void addEdge(string from, string to);

	void showVertex();
	void showEdge();
	void showEdge_In();

	void DepthFirstTraverse_Top(unsigned int index);

	void DepthFirstTraverse(unsigned int index, vector<bool> &visited);

	int getTotalVertices();

private:
	vector<vertex> a;
	//vector<bool> visited;


};

#endif /* ORTHOGONALLIST_HPP_ */
