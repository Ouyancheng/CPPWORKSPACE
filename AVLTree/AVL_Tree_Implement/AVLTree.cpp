/*
 * AVLTree.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: ouyan
 */

/*#include "AVLTree.hpp"

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
	tnode<T> *temp = pr;
	pr = pr->rchild;
	temp->rchild = pr->lchild;
	pr->lchild = temp;

	pr->bf = height(pr->lchild) - height(pr->rchild);
	pr->lchild->bf = height(pr->lchild->lchild) - height(pr->lchild->rchild);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::R_Rotate(tnode<T> *&pr) {
	tnode<T> *temp = pr;
	pr = pr->lchild;
	temp->lchild = pr->rchild;
	pr->rchild = temp;

	pr->bf = height(pr->lchild) - height(pr->rchild);
	pr->rchild->bf = height(pr->rchild->lchild) - height(pr->rchild->rchild);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::LR_Rotate(tnode<T> *&pr) {
	pr->lchild = L_Rotate(pr->lchild);
	pr = R_Rotate(pr);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::RL_Rotate(tnode<T> *&pr) {
	pr->rchild = R_Rotate(pr->rchild);
	pr = L_Rotate(pr);
	return pr;
}

template<class T>
tnode<T> * AVLTree<T>::insert(T element) {
	if (root == NULL) {
		root = new tnode<T>(element);
		return root;
	}

	tnode<T> **pp = &root;
	stack< snode<T> > s;

	while ((*pp) != NULL) {
		if (element < (*pp)->data) {
			pp = &((*pp)->lchild);
			s.push(snode<T>(pp, L));
		} else if (element > (*pp)->data) {
			pp = &((*pp)->rchild);
			s.push(snode<T>(pp, R));
		} else {
			cout << "ERROR: Element added twice! " << endl;
			return (tnode<T> *) NULL;
		}
	}

	snode<T> snodetemp = s.top();
	if (snodetemp.position==L) {
		(*(snodetemp.ppointer))->lchild=new tnode<T>(element);
	} else if (snodetemp.position==R) {
		(*(snodetemp.ppointer))->rchild=new tnode<T>(element);
	} else {
		cout << "ERROR: Stack top position undefined! " << endl;
	}
	return *(snodetemp.ppointer);
}





template<class T>
void AVLTree<T>::inorderTraverse(tnode<T> *p) {
	if (p!=NULL) {
		inorderTraverse(p->lchild);
		cout << p->data << " ";
		inorderTraverse(p->rchild);
	}
}

template<class T>
void AVLTree<T>::preorderTraverse(tnode<T> *p) {
	if (p!=NULL) {
		cout << p->data << " ";
		preorderTraverse(p->lchild);
		preorderTraverse(p->rchild);
	}
}

template<class T>
void AVLTree<T>::postorderTraverse(tnode<T> *p) {
	if (p!=NULL) {
		postorderTraverse(p->lchild);
		postorderTraverse(p->rchild);
		cout << p->data << " ";
	}
}

template<class T>
void AVLTree<T>::layerorderTraverse(tnode<T> *p) {
	queue< tnode<T> > q;
	q.push(p);

	while (!q.empty()) {
		tnode<T> *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->lchild!=NULL) {
			q.push(temp->lchild);
		}
		if (temp->rchild!=NULL) {
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
*/
//AVLTree<int> AVL;
