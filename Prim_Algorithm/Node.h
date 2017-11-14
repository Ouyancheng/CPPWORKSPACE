/*
 * Node.h
 *
 *  Created on: Aug 16, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
using namespace std;
struct edge {
	int weight;
	int headindex;
	int tailindex;
	edge *next;
};

struct vertex {
	string name;
	edge *first;
	int outdegree;
};

struct lownode {
	int weight;
	int fromindex;
};


#endif /* NODE_H_ */
