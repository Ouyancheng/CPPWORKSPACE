/*
 * Node.h
 *
 *  Created on: Aug 18, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
#include <climits>
using namespace std;



struct edge {
	unsigned int headindex;
	unsigned int tailindex;
	unsigned int weight;
	edge *next;
};

struct vertex {
	string name;
	edge *first;
};

struct lownode {
	unsigned int length;
	unsigned int fromindex;
	bool visited;

	lownode() {
		length=INT_MAX;
		fromindex=0;
		visited=false;
	}
};


#endif /* NODE_H_ */
