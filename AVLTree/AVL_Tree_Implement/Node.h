/*
 * Node.h
 *
 *  Created on: Aug 29, 2016
 *      Author: ouyan
 */

#ifndef NODE_H_
#define NODE_H_
#include <cstddef>
using namespace std;
#ifndef EH
#define EH 0
#endif /* EH */
#ifndef LH
#define LH 1
#endif /* LH */
#ifndef RH
#define RH -1
#endif /* RH */

template<typename T>
struct tnode {
	T data;
	tnode<T> *lchild;
	tnode<T> *rchild;
	int bf;

	tnode<T>(T data)
			: data(data), lchild(NULL), rchild(NULL), bf(EH) {

	}
};

enum pos { L, R, undefined };

template<typename T>
struct snode {
	tnode<T> **ppointer;
	pos position;

	snode<T>(tnode<T> **pointer, pos position)
			: ppointer(pointer), position(position) {

	}
	snode<T>() : ppointer(NULL), position(undefined) {

	}
};



#endif /* NODE_H_ */
