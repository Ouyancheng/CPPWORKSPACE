/*
 * Node.hpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#ifndef NODE_HPP_
#define NODE_HPP_
#include <string>
using namespace std;
struct qnode {
	unsigned int index;
	qnode *next;

	qnode(const unsigned int &_index) {
		index=_index;
		next=NULL;
	}
};

struct edge {
	unsigned int fromindex;
	unsigned int toindex;
	unsigned int weight;

	edge *next;

	edge(const unsigned int &_fromindex,
			const unsigned int &_toindex,
			const unsigned int &_weight=0u) {
		fromindex=_fromindex;
		toindex=_toindex;
		weight=_weight;
		next=NULL;
	}
};

struct vertex {
	std::string name;
	unsigned int indegree;

	edge *first;

	vertex(const std::string &_name) {
		name=_name;
		indegree=0u;
		first=NULL;
	}
};



#endif /* NODE_HPP_ */
