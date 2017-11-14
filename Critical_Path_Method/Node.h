/*
 * Node.h
 *
 *  Created on: Aug 22, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
using namespace std;
struct edge {
	unsigned int tailindex;
	unsigned int headindex;

	int weight;

	edge *next;
	edge *rnext;

	edge(unsigned int _tailindex = 0u, unsigned int _headindex = 0u, int _weight = 0) :
		tailindex(_tailindex), headindex(_headindex),
		weight(_weight),
		next(NULL), rnext(NULL) {
	}
};

struct vertex {
	string name;
	unsigned int indegree;
	unsigned int outdegree;

	edge *first;
	edge *rfirst;

	vertex(string name) :
			name(name), indegree(0u), outdegree(0u), first(NULL), rfirst(NULL) {
	}
};

#endif /* NODE_H_ */
