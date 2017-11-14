/*
 * avltree.hpp
 *
 *  Created on: Aug 29, 2016
 *      Author: ouyan
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include <iostream>
#include <queue>
using namespace std;

template<class T>
class tnode {
public:
	T data;
	unsigned int height;
	tnode *lchild;
	tnode *rchild;

	tnode(T data)
		: data(data), height(0u), lchild(nullptr), rchild(nullptr) {

	}
};

template<class T>
class avltree {
private:
	tnode<T> *root;
public:

	avltree() {
		root = (tnode<T> *)nullptr;
	}

	virtual ~avltree() {
		destroyTree(root);
	}

	//Preorder Traverse
	void preorder() {
		preorder(root);
	}
	//Inorder Traverse
	void inorder() {
		inorder(root);
	}
	//Postorder Traverse
	void postorder() {
		postorder(root);
	}
	//Layerorder Traverse
	void layerorder() {
		layerorder(root);
	}

	//Get the height of the whole tree
	unsigned int height() {
		return height(root);
	}

	void insert(T data) {
		insert(root, data);
	}

	tnode<T> * search(T data) {
		return search(root, data);
	}

	void remove(T data) {
		tnode<T> *p;
		p = search(root, data);
		if (p != nullptr) {
			root = remove(root, p);
		}
	}




private:
	void destroyTree(tnode<T> *p) {
		if (p != nullptr) {
			destroyTree(p->lchild);
			destroyTree(p->rchild);
			delete p;
		}
	}

	void preorder(tnode<T> *p) {
		if (p != nullptr) {
			cout << p->data << " ";
			preorder(p->lchild);
			preorder(p->rchild);
		}
	}

	void inorder(tnode<T> *p) {
		if (p != nullptr) {
			inorder(p->lchild);
			cout << p->data << " ";
			inorder(p->rchild);
		}
	}

	void postorder(tnode<T> *p) {
		if (p != nullptr) {
			postorder(p->lchild);
			postorder(p->rchild);
			cout << p->data << " ";
		}
	}

	void layerorder(tnode<T> *p) {
		queue< tnode<T> * > Queue;
		Queue.push(p);
		while (!Queue.empty()) {
			tnode<T> *temp;
			temp = Queue.front();
			cout << temp->data << " " << temp->height << endl;
			Queue.pop();
			if (temp->lchild != nullptr) {
				Queue.push(temp->lchild);
			}
			if (temp->rchild != nullptr) {
				Queue.push(temp->rchild);
			}
		}
	}

	unsigned int height(tnode<T> *p) {
		if (p == nullptr) {
			return 0u;
		}
		return p->height;
	}

	unsigned int max(unsigned int a, unsigned int b) {
		return a > b ? a : b;
	}

	//Rotate left, corresponding to the RR situation
	tnode<T> * L_Rotate(tnode<T> *p) {
		tnode<T> *q;
		q = p->rchild;
		p->rchild = q->lchild;
		q->lchild = p;

		//Refresh the height of p and q
		p->height = max(height(p->lchild), height(p->rchild)) + 1;
		q->height = max(height(q->lchild), height(q->rchild)) + 1;

		return q;
	}

	//Rotate right, corresponding to the LL situation
	tnode<T> * R_Rotate(tnode<T> *p) {
		tnode<T> *q;
		q = p->lchild;
		p->lchild = q->rchild;
		q->rchild = p;

		//Refresh the height of p and q
		p->height = max(height(p->lchild), height(p->rchild)) + 1;
		q->height = max(height(p->lchild), height(p->rchild)) + 1;

		return q;
	}

	//Rotate left then rotate right, corresponding to the LR situation
	tnode<T> * LR_Rotate(tnode<T> *p) {
		p->lchild = L_Rotate(p->lchild);
		return R_Rotate(p);
	}

	//Rotate right then rotate left, corresponding to the RL situation
	tnode<T> * RL_Rotate(tnode<T> *p) {
		p->rchild = R_Rotate(p->rchild);
		return L_Rotate(p);
	}

	tnode<T> * insert(tnode<T> *&p, T data) {
		if (p == nullptr) {
			p = new tnode<T>(data);
			if (p == nullptr) {
				cerr << "ERROR: Memory allocation failed! " << endl;
			}
		}
		else {
			if (data < p->data) {
				p->lchild = insert(p->lchild, data);

				//If the sub tree is imbalance, we should re-balance it
				if (height(p->lchild) - height(p->rchild) >= 2) {
					//The LL situation
					if (data < p->lchild->data) {
						p = R_Rotate(p);
					}
					//The LR situation
					else {
						p = LR_Rotate(p);
					}
				}
			}
			else if (data > p->data) {
				p->rchild = insert(p->rchild, data);

				//If the sub tree is imbalance, we should re-balance it
				if (height(p->rchild) - height(p->lchild) >= 2) {
					//The RL situation
					if (data < p->rchild->data) {
						p = RL_Rotate(p);
					}
					//The RR situation
					else {
						p = L_Rotate(p);
					}
				}
			}
			else {
				cerr << "An element cannot be added twice! " << endl;
				return (tnode<T> *)nullptr;
			}
		}

		p->height = max(height(p->lchild), height(p->rchild)) + 1;

		return p;
	}

	tnode<T> * remove(tnode<T> *&p, tnode<T> *n) {
		if (p == nullptr || n == nullptr) {
			return (tnode<T> *)nullptr;
		}
		else if (n->data < p->data) {
			p->lchild = remove(p->lchild, n);
			if (height(p->rchild) - height(p->rchild) >= 2) {
				if (height(p->rchild->lchild) <= height(p->rchild->rchild)) {
					p->rchild = R_Rotate(p->rchild);
				}
				else {
					p->rchild = RL_Rotate(p->rchild);
				}
			}
		}
		else if (n->data > p->data) {
			p->rchild = remove(p->rchild, n);
			if (height(p->lchild) - height(p->rchild) >= 2) {
				if (height(p->lchild->lchild) >= height(p->lchild->rchild)) {
					p->lchild = L_Rotate(p->lchild);
				}
				else {
					p->lchild = LR_Rotate(p->lchild);
				}
			}
		}
		else {
			tnode<T> *mostp = p;
			if (p->lchild != nullptr && p->rchild != nullptr) {
				if (height(p->lchild) > height(p->rchild)) {
					mostp = rightmost(p->lchild);
					//swap(mostp->data, p->data);
					p->data = mostp->data;
					p->lchild = remove(p->lchild, mostp);
				}
				else {
					mostp = leftmost(p->rchild);
					//swap(mostp->data, p->data);
					p->data = mostp->data;
					p->rchild = remove(p->rchild, mostp);
				}
			}
			else {
				tnode<T> *tmp = p;
				p = (p->rchild != nullptr) ? p->rchild : p->lchild;
				delete tmp;

			}
		}
		return p;
	}

	void swap(T &a, T &b) {
		T temp;
		temp = a;
		a = b;
		b = temp;
	}

	tnode<T> * leftmost(tnode<T> *p) {
		tnode<T> *temp = p;
		while (temp->lchild != nullptr) {
			temp = temp->lchild;
		}
		return temp;
	}

	tnode<T> * rightmost(tnode<T> *p) {
		tnode<T> *temp = p;
		while (temp->rchild) {
			temp = temp->rchild;
		}
		return temp;
	}

	tnode<T> * search(tnode<T> *tree, T data) {
		if (tree->data == data || tree==nullptr) {
			return tree;
		}
		else {
			if (data < tree->data) {
				return search(tree->lchild, data);
			}
			else {
				return search(tree->rchild, data);
			}
		}
	}
};




#endif /* AVLTREE_HPP_ */
