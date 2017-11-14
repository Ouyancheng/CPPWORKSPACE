/*
 * Node.hpp
 *
 *  Created on: Aug 12, 2016
 *      Author: ouyan
 */

#ifndef NODE_HPP_
#define NODE_HPP_
#include <string>
using namespace std;

struct edge {
	string fromname;
	unsigned int fromindex;
	edge *outlink;

	string toname;
	unsigned int toindex;
	edge *inlink;
};

struct vertex {
	string name;
	edge *firstin;
	edge *firstout;
};



#endif /* NODE_HPP_ */
