/*
 * AVLTree.h
 *
 *  Created on: Aug 29, 2016
 *      Author: ouyan
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include "Node.h"
#include <stack>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Vector.hpp"

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif /* MAX */
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif /* MIN */

template<class T>
class AVLTree {
public:
	AVLTree();
	virtual ~AVLTree();

	tnode<T> * insert(T element);
	tnode<T> * remove(T element);

	void show();

private:
	tnode<T> *root;

	void destroy(tnode<T> *p);
	int height(tnode<T> *p);

	tnode<T> * L_Rotate(tnode<T> *&pr);
	tnode<T> * R_Rotate(tnode<T> *&pr);
	tnode<T> * LR_Rotate(tnode<T> *&pr);
	tnode<T> * RL_Rotate(tnode<T> *&pr);

	tnode<T> ** findLeftmost(tnode<T> *&p, stack<snode<T> > &s);
	tnode<T> ** findRightmost(tnode<T> *&p, stack<snode<T> > &s);

	void inorderTraverse(tnode<T> *p);
	void preorderTraverse(tnode<T> *p);
	void postorderTraverse(tnode<T> *p);
	void layerorderTraverse(tnode<T> *p);

	void swap(T &a, T &b);
};

template<class T>
AVLTree<T>::AVLTree() {
	// TODO Auto-generated constructor stub
	root = (tnode<T> *) NULL;
}

template<class T>
AVLTree<T>::~AVLTree() {
	// TODO Auto-generated destructor stub
	destroy(root);
}

template<class T>
void AVLTree<T>::destroy(tnode<T> *p) {
	if (p != NULL) {
		destroy(p->lchild);
		destroy(p->rchild);
		delete p;
	}
}

template<class T>
int AVLTree<T>::height(tnode<T> *p) {
	if (p == NULL) {
		return 0;
	} else {
		return MAX(height(p->lchild), height(p->rchild)) + 1;
	}
}

template<class T>
tnode<T> * AVLTree<T>::L_Rotate(tnode<T> *&pr) {
	//cout << "L_Rotating: " << pr->data << endl;
	tnode<T> *temp = pr;
	pr = pr->rchild;
	temp->rchild = pr->lchild;
	pr->lchild = temp;

	pr->bf = height(pr->lchild) - height(pr->rchild);
	//cout << pr->data << "->bf=" << pr->bf << endl;
	pr->lchild->bf = height(pr->lchild->lchild) - height(pr->lchild->rchild);
	//cout << pr->lchild->data << "->bf=" << pr->lchild->bf << endl;
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::R_Rotate(tnode<T> *&pr) {
	//cout << "R_Rotating: " << pr->data << endl;
	tnode<T> *temp = pr;
	pr = pr->lchild;
	temp->lchild = pr->rchild;
	pr->rchild = temp;

	pr->bf = height(pr->lchild) - height(pr->rchild);
	//cout << pr->data << "->bf=" << pr->bf << endl;
	pr->rchild->bf = height(pr->rchild->lchild) - height(pr->rchild->rchild);
	//cout << pr->rchild->data << "->bf=" << pr->rchild->bf << endl;
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::LR_Rotate(tnode<T> *&pr) {
	//cout << "LR_Rotating: " << pr->data << endl;
	pr->lchild = L_Rotate(pr->lchild);
	pr = R_Rotate(pr);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::RL_Rotate(tnode<T> *&pr) {
	//cout << "RL_Rotating: " << pr->data << endl;
	pr->rchild = R_Rotate(pr->rchild);
	pr = L_Rotate(pr);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::insert(T element) {
	//cout << "Adding " << element << endl;
	if (root == NULL) {
		root = new tnode<T>(element);
		return root;
	}

	tnode<T> **pp = &root;
	vector<snode<T> > s;

	while ((*pp) != NULL) {

		if (element < (*pp)->data) {
			s.push_back(snode<T>(pp, L));
			pp = &((*pp)->lchild);

		} else if (element > (*pp)->data) {
			s.push_back(snode<T>(pp, R));
			pp = &((*pp)->rchild);

		} else {
			cout << "ERROR: Element added twice! " << endl;
			return (tnode<T> *) NULL;
		}

	}

	snode<T> snodetemp = s.back();
	*(pp) = new tnode<T>(element);

	/*cout << "Stack size: " << s.size() << endl;
	 for (unsigned int i = 0; i < s.size(); i++) {
	 cout << (**s[i].ppointer).data << " position: " << s[i].position << endl;
	 }
	 cout << endl;*/

	tnode<T> **pptemp;
	snode<T> snt = s.back();

	do {
		snt = s.back();
		pptemp = snt.ppointer;
		s.pop_back();
		if ((*pptemp)->bf == EH) {
			if (snt.position == L) {
				(*pptemp)->bf = LH;
				//cout << (*pptemp)->data << "->bf=" << "LH" << endl;
			} else if (snt.position == R) {
				(*pptemp)->bf = RH;
				//cout << (*pptemp)->data << "->bf=" << "RH" << endl;
			} else {
				cout << "ERROR: EH position undefined! \n";
			}
		} else if ((*pptemp)->bf == LH) {
			if (snt.position == R) {
				(*pptemp)->bf = EH;
				//cout << (*pptemp)->data << "->bf=" << "EH" << endl;
				break;
			} else if (snt.position == L) {
				//L
				tnode<T> *left = (*pptemp)->lchild;
				if (element < left->data) {
					//LL
					*(pptemp) = R_Rotate(*(pptemp));
					//cout << "LL\n";
					break;
				} else if (element > left->data) {
					//LR
					*(pptemp) = LR_Rotate(*(pptemp));
					//cout << "LR\n";
					break;
				}
			} else {
				cout << "ERROR: LH position undefined! \n";
			}
		} else if ((*pptemp)->bf == RH) {
			if (snt.position == L) {
				(*pptemp)->bf = EH;
				//cout << (*pptemp)->data << "->bf=" << "EH" << endl;
				break;
			} else if (snt.position == R) {
				//R
				tnode<T> *right = (*pptemp)->rchild;
				if (element > right->data) {
					//RR
					*(pptemp) = L_Rotate(*(pptemp));
					//cout << "RR\n";
					break;
				} else if (element < right->data) {
					*(pptemp) = RL_Rotate(*(pptemp));
					//cout << "RL\n";
					break;
				}
			} else {
				cout << "ERROR: RH position undefined! \n";
			}
		}
	} while (*pptemp != root);

	s.clear();
	return *(snodetemp.ppointer);
}

template<class T>
tnode<T> * AVLTree<T>::remove(T element) {
	if (root == NULL) {
		return (tnode<T> *) NULL;
	}

	tnode<T> **pp = &root;
	vector<snode<T> > s;

	while ((*pp)->data != element) {
		if (element < (*pp)->data) {
			//cout << "Pushed stack L" << endl;
			s.push_back(snode<T>(pp, L));
			pp = &((*pp)->lchild);
		} else if (element > (*pp)->data) {
			//cout << "Pushed stack R" << endl;
			s.push_back(snode<T>(pp, R));
			pp = &((*pp)->rchild);
		} else {
			cerr << "ERROR: Logic error! " << endl;
			return (tnode<T> *) NULL;
		}
	}

	cout << "Stack size: " << s.size() << endl;
	for (unsigned int i = 0; i < s.size(); i++) {
		cout << (*s[i].ppointer)->data << " ";
	}
	cout << endl;

	if ((*pp)->lchild == NULL || (*pp)->rchild == NULL) {
		tnode<T> *temp = (*pp);
		(*pp) = (((*pp)->lchild != NULL) ? ((*pp)->lchild) : ((*pp)->rchild));
		delete temp;

		while (!s.empty()) {
			snode<T> snt = s.back();
			s.pop_back();
			if ((*snt.ppointer)->bf == EH) {
				if (snt.position == L) {
					(*snt.ppointer)->bf = RH;
				} else if (snt.position == R) {
					(*snt.ppointer)->bf = LH;
				} else {
					cerr << "ERROR: EH Position undefined! " << endl;
				}
			} else if ((*snt.ppointer)->bf == LH) {
				if (snt.position == R) {
					//L
					tnode<T> **ppleft = &((*snt.ppointer)->lchild);
					if (height((*ppleft)->lchild)
							>= height((*ppleft)->rchild)) {
						//LL
						R_Rotate(*(pp));
						break;
					} else {
						//LR
						LR_Rotate(*(pp));
						break;
					}
				} else if (snt.position == L) {
					(*snt.ppointer)->bf = EH;
					break;
				} else {
					cerr << "ERROR: LH Position undefined! " << endl;
				}
			} else {
				if (snt.position == R) {
					(*snt.ppointer)->bf = EH;
					break;
				} else if (snt.position == L) {
					//R
					tnode<T> **ppright = &((*pp)->rchild);
					if (height((*ppright)->lchild)
							<= height((*ppright)->rchild)) {
						//RR
						L_Rotate(*(pp));
						break;
					} else {
						//RL
						RL_Rotate(*(pp));
						break;
					}
				} else {
					cerr << "ERROR: RH Position undefined! " << endl;
				}
			}
		}
	} else if ((*pp)->lchild != NULL && (*pp)->rchild != NULL) {
		stack<snode<T> > Stack;
		if (height((*pp)->lchild) > height((*pp)->rchild)) {
			tnode<T> **rightmost = findRightmost((*pp)->lchild, Stack);
			swap((*rightmost)->data, (*pp)->data);
			//remove(element);

			tnode<T> *tempptr = (*rightmost);
			(*rightmost) = (*rightmost)->lchild;
			while (!Stack.empty()) {
				snode<T> snt = Stack.top();
				Stack.pop();
				if ((*snt.ppointer)->bf == EH) {
					if (snt.position == L) {
						(*snt.ppointer)->bf = RH;
					} else if (snt.position == R) {
						(*snt.ppointer)->bf = LH;
					} else {
						cerr << "ERROR: EH Position undefined! " << endl;
					}
				} else if ((*snt.ppointer)->bf == LH) {
					if (snt.position == R) {
						//L
						tnode<T> **ppleft = &((*snt.ppointer)->lchild);
						if (height((*ppleft)->lchild)
								>= height((*ppleft)->rchild)) {
							//LL
							R_Rotate(*(pp));
							break;
						} else {
							//LR
							LR_Rotate(*(pp));
							break;
						}
					} else if (snt.position == L) {
						(*snt.ppointer)->bf = EH;
						break;
					} else {
						cerr << "ERROR: LH Position undefined! " << endl;
					}
				} else {
					if (snt.position == R) {
						(*snt.ppointer)->bf = EH;
						break;
					} else if (snt.position == L) {
						//R
						tnode<T> **ppright = &((*pp)->rchild);
						if (height((*ppright)->lchild)
								<= height((*ppright)->rchild)) {
							//RR
							L_Rotate(*(pp));
							break;
						} else {
							//RL
							RL_Rotate(*(pp));
							break;
						}
					} else {
						cerr << "ERROR: RH Position undefined! " << endl;
					}
				}
			}
			delete tempptr;

		} else {
			tnode<T> **leftmost = findLeftmost((*pp)->rchild, Stack);
			swap((*leftmost)->data, (*pp)->data);

			//remove(element);

			tnode<T> *tempptr = (*leftmost);
			(*leftmost) = (*leftmost)->rchild;

			while (!Stack.empty()) {
				snode<T> snt = Stack.top();
				Stack.pop();
				if ((*snt.ppointer)->bf == EH) {
					if (snt.position == L) {
						(*snt.ppointer)->bf = RH;
					} else if (snt.position == R) {
						(*snt.ppointer)->bf = LH;
					} else {
						cerr << "ERROR: EH Position undefined! " << endl;
					}
				} else if ((*snt.ppointer)->bf == LH) {
					if (snt.position == R) {
						//L
						tnode<T> **ppleft = &((*snt.ppointer)->lchild);
						if (height((*ppleft)->lchild)
								>= height((*ppleft)->rchild)) {
							//LL
							R_Rotate(*(pp));
							break;
						} else {
							//LR
							LR_Rotate(*(pp));
							break;
						}
					} else if (snt.position == L) {
						(*snt.ppointer)->bf = EH;
						break;
					} else {
						cerr << "ERROR: LH Position undefined! " << endl;
					}
				} else {
					if (snt.position == R) {
						(*snt.ppointer)->bf = EH;
						break;
					} else if (snt.position == L) {
						//R
						tnode<T> **ppright = &((*pp)->rchild);
						if (height((*ppright)->lchild)
								<= height((*ppright)->rchild)) {
							//RR
							L_Rotate(*(pp));
							break;
						} else {
							//RL
							RL_Rotate(*(pp));
							break;
						}
					} else {
						cerr << "ERROR: RH Position undefined! " << endl;
					}
				}
			}

			delete tempptr;
		}
	}

	return (*pp);

}

template<class T>
tnode<T> ** AVLTree<T>::findLeftmost(tnode<T> *&p, stack<snode<T> > &s) {
	tnode<T> **pp = &p;
	while ((*pp)->lchild != NULL) {
		s.push(snode<T>(pp, L));
		pp = &((*pp)->lchild);
	}
	return pp;
}

template<class T>
tnode<T> ** AVLTree<T>::findRightmost(tnode<T> *&p, stack<snode<T> > &s) {
	tnode<T> **pp = &p;
	while ((*pp)->rchild != NULL) {
		s.push(snode<T>(pp, R));
		pp = &((*pp)->rchild);
	}
	return pp;
}

template<class T>
void AVLTree<T>::swap(T &a, T &b) {
	T c;
	c = a;
	a = b;
	b = c;
}

template<class T>
void AVLTree<T>::inorderTraverse(tnode<T> *p) {
	if (p != NULL) {
		inorderTraverse(p->lchild);
		cout << p->data << " ";
		inorderTraverse(p->rchild);
	}
}

template<class T>
void AVLTree<T>::preorderTraverse(tnode<T> *p) {
	if (p != NULL) {
		cout << p->data << " ";
		preorderTraverse(p->lchild);
		preorderTraverse(p->rchild);
	}
}

template<class T>
void AVLTree<T>::postorderTraverse(tnode<T> *p) {
	if (p != NULL) {
		postorderTraverse(p->lchild);
		postorderTraverse(p->rchild);
		cout << p->data << " ";
	}
}

template<class T>
void AVLTree<T>::layerorderTraverse(tnode<T> *p) {
	queue<tnode<T> *> q;
	q.push(p);

	while (!q.empty()) {
		tnode<T> *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->lchild != NULL) {
			q.push(temp->lchild);
		}
		if (temp->rchild != NULL) {
			q.push(temp->rchild);
		}
	}
}

template<class T>
void AVLTree<T>::show() {
	cout << "Inorder: " << endl;
	inorderTraverse(root);
	cout << "\nPreorder: " << endl;
	preorderTraverse(root);
	cout << "\nPostorder: " << endl;
	postorderTraverse(root);
	cout << "\nLayerorder: " << endl;
	layerorderTraverse(root);
	cout << endl;
}

//AVLTree<int> AVL;

#endif /* AVLTREE_HPP_ */
