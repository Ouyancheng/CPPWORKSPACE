/*
 * Node.h
 *
 *  Created on: Aug 26, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <cstddef>
using namespace std;
struct node {
	int data;
	int bf;
	node *lchild;
	node *rchild;

	node(int _data = 0) : data(_data), bf(0), lchild(NULL), rchild(NULL) {

	}
};

enum position { L, R };

struct snode {
	node *&p;
	position pos;

	snode(node *_p, position _pos) : p(_p), pos(_pos) {

	}
};

#ifndef LH
#define LH 1
#endif //! LH

#ifndef RH
#define RH -1
#endif //! RH

#ifndef EH
#define EH 0
#endif //! EH

#endif /* NODE_H_ */
