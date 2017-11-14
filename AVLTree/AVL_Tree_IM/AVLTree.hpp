/*
 * AVLTree.hpp
 *
 *  Created on: Sep 10, 2016
 *      Author: ouyan
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include "Node.hpp"
#include <iostream>
#include <deque>
using namespace std;

#ifndef _MAX
#define _MAX(a,b) (((a)>(b))?(a):(b));
#endif //! _MAX


template<class INDEX, class DATA>
class AVLTree {
private:
	tnode<INDEX, DATA> *root;
public:
	AVLTree() {
		root=nullptr;
	}
	virtual ~AVLTree() {
		__destroy(root);
	}

	bool insert(INDEX index, DATA data) {
		cout << "INSERTING: " << "INDEX: " << index << " DATA: " << data << endl;
		if (root==nullptr) {
			root=new tnode<INDEX, DATA>(index, data);
			return true;
		}

		tedge<INDEX, DATA> *pte=&root;
		deque< tedge<INDEX, DATA> * > Stack;
		while ((*pte)!=nullptr) {
			if (index < (*pte)->index) {
				Stack.push_back(pte);
				pte=&((*pte)->lchild);
			} else {
				Stack.push_back(pte);
				pte=&((*pte)->rchild);
			}
		}
		(*pte)=new tnode<INDEX, DATA>(index, data);

		_Refresh_Height(pte, Stack);

		return true;
	}

	bool remove(INDEX index) {
		tedge<INDEX, DATA> *pte=&root;
		deque< tedge<INDEX, DATA> * > Stack;
		while ((*pte)!=nullptr) {
			if (index < (*pte)->index) {
				Stack.push_back(pte);
				pte=&((*pte)->lchild);
			} else if ((*pte)->index < index) {
				Stack.push_back(pte);
				pte=&((*pte)->rchild);
			} else {
				break;
			}
		}

		if ((*pte)==nullptr) {
			return false;
		}

		if ((*pte)->lchild==nullptr || (*pte)->rchild==nullptr) {
			removeleaf(pte, Stack);
		} else {
			removenonleaf(pte, Stack);
		}
		return true;
	}

	void inorder() {
		inorder(root);
		cout << endl;
	}
	void preorder() {
		preorder(root);
		cout << endl;
	}
	void postorder() {
		postorder(root);
		cout << endl;
	}
	void layerorder() {
		layerorder(root);
		cout << endl;
	}

private:
	void __destroy(tnode<INDEX, DATA> *p) {
		if (p!=nullptr) {
			__destroy(p->lchild);
			__destroy(p->rchild);
			delete p;
		}
	}

	int height(tnode<INDEX, DATA> *p) const {
		if (p==nullptr) {
			return 0;
		} else {
			return p->height;
		}
	}

	void inorder(tnode<INDEX, DATA> *p) const {
		if (p!=nullptr) {
			inorder(p->lchild);
			cout << p->index << ": " << p->data << "  ";
			inorder(p->rchild);
		}
	}

	void preorder(tnode<INDEX, DATA> *p) const {
		if (p!=nullptr) {
			cout << p->index << ": " << p->data << "  ";
			preorder(p->lchild);
			preorder(p->rchild);
		}
	}

	void postorder(tnode<INDEX, DATA> *p) const {
		if (p!=nullptr) {
			postorder(p->lchild);
			postorder(p->rchild);
			cout << p->index << ": " << p->data << "  ";
		}
	}

	void layerorder(tnode<INDEX, DATA> *p) const {
		deque< tnode<INDEX, DATA> * > Queue;
		Queue.push_front(p);


		tnode<INDEX, DATA> *tempptr;
		while (!Queue.empty()) {
			tempptr=Queue.back();
			Queue.pop_back();
			cout << tempptr->index << ": " << tempptr->data << "  ";
			if (tempptr->lchild!=nullptr) {
				Queue.push_front(tempptr->lchild);
			}

			if (tempptr->rchild!=nullptr) {
				Queue.push_front(tempptr->rchild);
			}
		}
	}

	tedge<INDEX, DATA> * findLeftmost(tedge<INDEX, DATA> *teptr) {
		tedge<INDEX, DATA> *tempteptr=teptr;
		while ((*tempteptr)->lchild!=nullptr) {
			tempteptr=&((*tempteptr)->lchild);
		}

		return tempteptr;
	}

	tedge<INDEX, DATA> * findRightmost(tedge<INDEX, DATA> *teptr) {
		tedge<INDEX, DATA> *tempteptr=teptr;
		while ((*tempteptr)->rchild!=nullptr) {
			tempteptr=&((*tempteptr)->rchild);
		}

		return tempteptr;
	}

	tedge<INDEX, DATA> * L_Rotate(tedge<INDEX, DATA> *pte) {
		cout << "L_Rotating " << endl;
		tnode<INDEX, DATA> *tempptn=(*pte);
		(*pte)=(*pte)->rchild;
		tempptn->rchild=(*pte)->lchild;
		(*pte)->lchild=tempptn;

		tempptn->height=1+_MAX(height(tempptn->lchild), height(tempptn->rchild));
		(*pte)->height=1+_MAX(height((*pte)->lchild), height((*pte)->rchild));

		return pte;
	}

	tedge<INDEX, DATA> * R_Rotate(tedge<INDEX, DATA> *pte) {
		cout << "R_Rotating " << endl;
		tnode<INDEX, DATA> *tempptn=(*pte);
		(*pte)=(*pte)->lchild;
		tempptn->lchild=(*pte)->rchild;
		(*pte)->rchild=tempptn;

		tempptn->height=1+_MAX(height(tempptn->lchild), height(tempptn->rchild));
		(*pte)->height=1+_MAX(height((*pte)->lchild), height((*pte)->rchild));

		//cout << "R_Rotating complete! " << endl;
		return pte;
	}

	tedge<INDEX, DATA> * LR_Rotate(tedge<INDEX, DATA> *pte) {
		cout << "LR_Rotating " << endl;
		(*pte)->lchild=*(L_Rotate(&((*pte)->lchild)));
		return R_Rotate(pte);
	}

	tedge<INDEX, DATA> * RL_Rotate(tedge<INDEX, DATA> *pte) {
		cout << "RL_Rotating " << endl;
		(*pte)->rchild=*(R_Rotate(&((*pte)->rchild)));
		return L_Rotate(pte);
	}

	void _Refresh_Height(tedge<INDEX, DATA> *targetpte,
			deque< tedge<INDEX, DATA> * > &Stack) {
		tedge<INDEX, DATA> *pte;

		while(!Stack.empty()) {
			pte=Stack.back();
			Stack.pop_back();
			(*pte)->height=1+_MAX(height((*pte)->lchild), height((*pte)->rchild));

			if (height((*pte)->lchild) - height((*pte)->rchild) >= 2) {
				//L
				tedge<INDEX, DATA> *lpte=&((*pte)->lchild);
				if ((*targetpte)->index < (*lpte)->index) {
					//LL
					R_Rotate(pte);
					break;
				} else {
					//LR
					LR_Rotate(pte);
					break;
				}
			}
			else if (height((*pte)->rchild) - height((*pte)->lchild) >= 2) {
				//R
				tedge<INDEX, DATA> *rpte=&((*pte)->rchild);
				if ((*targetpte)->index < (*rpte)->index) {
					//RL
					RL_Rotate(pte);
					break;
				} else {
					//RR
					L_Rotate(pte);
					break;
				}
			}
			else if (height((*pte)->lchild) == height((*pte)->rchild)) {
				break;
			}

		}
	}

	void removeleaf(tedge<INDEX, DATA> *pte, deque< tedge<INDEX, DATA> * > &Stack) {
		tnode<INDEX, DATA> *ptn=(*pte);
		(*pte)=((*pte)->lchild!=nullptr) ? ((*pte)->lchild) : ((*pte)->rchild);
		delete ptn;

		while (!Stack.empty()) {
			tedge<INDEX, DATA> *pte;
			pte=Stack.back();
			Stack.pop_back();

			(*pte)->height=1+_MAX(height((*pte)->lchild), height((*pte)->rchild));

			if (height((*pte)->lchild) - height((*pte)->rchild) >= 2) {
				//L
				tedge<INDEX, DATA> *lpte=&((*pte)->lchild);
				if (height((*lpte)->lchild) > height((*lpte)->rchild)) {
					//LL;
					R_Rotate(lpte);
					break;
				} else {
					//LR
					LR_Rotate(lpte);
					break;
				}

			}
			else if (height((*pte)->rchild) - height((*pte)->lchild) >= 2) {
				//R
				tedge<INDEX, DATA> *rpte=&((*pte)->rchild);
				if (height((*rpte)->lchild) > height((*rpte)->rchild)) {
					//RL
					RL_Rotate(rpte);
					break;
				} else {
					//RR
					L_Rotate(rpte);
					break;
				}

			}
		}

	}

	void removenonleaf(tedge<INDEX,DATA> *pte, deque< tedge<INDEX, DATA> * > &Stack) {
		tedge<INDEX, DATA> *temppte=pte;
		if (height((*pte)->lchild) < height((*pte)->rchild)) {
			temppte=findLeftmost(&((*pte)->rchild));
		} else {
			temppte=findRightmost(&((*pte)->lchild));
		}

		swap(pte, temppte);

		removeleaf(temppte, Stack);

	}

	void swap(tedge<INDEX, DATA> *a, tedge<INDEX, DATA> *b) {
		DATA tempdata=(*a)->data;
		INDEX tempindex=(*a)->index;
		(*a)->data=(*b)->data;
		(*b)->data=tempdata;
		(*a)->index=(*b)->index;
		(*b)->index=tempindex;
	}
};

#endif /* AVLTREE_HPP_ */
