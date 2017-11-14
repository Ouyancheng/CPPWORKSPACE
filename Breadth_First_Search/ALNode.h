/*
 * ALNode.h
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#ifndef ALNODE_H_
#define ALNODE_H_
#include <string>
struct edge {
	std::string headname;
	int headindex;
	edge *next;
};

struct vertex {
	std::string name;
	int outdegree;
	edge *firstout;
};



#endif /* ALNODE_H_ */
