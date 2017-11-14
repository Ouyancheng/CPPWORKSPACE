/*
 * Node.hpp
 *
 *  Created on: Sep 10, 2016
 *      Author: ouyan
 */

#ifndef NODE_HPP_
#define NODE_HPP_

template<class INDEX, class DATA>
class tnode {
public:
	INDEX index;
	DATA data;
	int height;
	tnode<INDEX, DATA> *lchild;
	tnode<INDEX, DATA> *rchild;

	tnode(INDEX index, DATA data) : index(index), data(data),
			height(1), lchild(nullptr), rchild(nullptr) {

	}
};

template<class INDEX, class DATA>
using tedge = tnode<INDEX, DATA> *;
// This is the enhanced typedef


#endif /* NODE_HPP_ */
