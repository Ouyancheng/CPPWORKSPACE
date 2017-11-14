/*
 * Node.h
 *
 *  Created on: Aug 17, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
using namespace std;
struct edge {
	unsigned toindex;
	unsigned fromindex;
	int weight;
	edge *next;

	bool operator <(edge &another) {
		if (this->weight<another.weight) {
			return true;
		} else {
			return false;
		}
	}
};

struct vertex {
	string name;
	unsigned degree;
	edge *first;
};



#endif /* NODE_H_ */
