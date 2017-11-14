#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

#ifndef EH
#define EH 0
#endif //! EH
#ifndef LH
#define LH 1
#endif //! LH
#ifndef RH
#define RH -1
#endif //! RH

#ifndef MAX
#define MAX(a, b) (((a)>(b))?(a):(b))
#endif //! MAX
#ifndef MIN
#define MIN(a, b) (((a)<(b))?(a):(b))
#endif //! MIN

enum position {
	L, R
};

template<class INDEX, class DATA>
class tnode {
public:
	INDEX index;
	DATA data;
	int height;

	tnode<INDEX, DATA> *lchild;
	tnode<INDEX, DATA> *rchild;

	tnode<INDEX, DATA>(INDEX index, DATA data)
		: index(index), data(data), height(1), lchild(nullptr), rchild(nullptr) {

		}

};

//#ifndef tedge
//#define tedge tnode<INDEX, DATA> *
//#endif //! tedge

template<class INDEX, class DATA>
using tedge = tnode<INDEX, DATA> *;

template<class INDEX, class DATA>
class selem {
public:
	tedge<INDEX, DATA> *pte;
	position pos;
	selem(tedge<INDEX, DATA> *pte = nullptr, position pos = L)
		: pte(pte), pos(pos) {

		}
};

template<class INDEX, class DATA>
class BSTree {
private:
	tnode<INDEX, DATA> *root;

	DATA _temp;

public:
	BSTree() {
		root=nullptr;
	}
	~BSTree() {
		__destroy(root);
	}

	void inorderTraverse() {
		inorderTraverse(root);
		cout << endl;
	}
	void preorderTraverse() {
		preorderTraverse(root);
		cout << endl;
	}
	void postorderTraverse() {
		postorderTraverse(root);
		cout << endl;
	}
	void layerorderTraverse() {
		layerorderTraverse(root);
		cout << endl;
	}

	void show() {
		cout << "Inorder: " << endl;
		inorderTraverse();
		cout << "Preorder: " << endl;
		preorderTraverse();
		cout << "Postorder: " << endl;
		postorderTraverse();
		cout << "Layerorder: " << endl;
		layerorderTraverse();
		cout << endl;
	}

	bool insert(INDEX index, DATA data) {
		cout << "Inserting index: " << index << endl;
		if (root==nullptr) {
			root=new tnode<INDEX, DATA>(index, data);
			return true;
		}

		tedge<INDEX, DATA> *pte=&root;
		deque< selem<INDEX, DATA> > s;
		while (*pte!=nullptr) {
			if (index < (*pte)->index) {
				s.push_back(selem<INDEX, DATA>(pte, L));
				pte=&((*pte)->lchild);
			} else {
				s.push_back(selem<INDEX, DATA>(pte, R));
				pte=&((*pte)->rchild);
			}
		}

		(*pte)=new tnode<INDEX, DATA>(index, data);
		refresh_height(pte, s, index);

		return true;
	}

	bool remove(INDEX index) {
		tedge<INDEX, DATA> *pte=&root;
		deque< selem<INDEX, DATA> > s;
		while ((*pte)!=nullptr) {
			if (index < (*pte)->index) {
				s.push_back(selem<INDEX, DATA>(pte, L));
				pte=&((*pte)->lchild);
			}
			else if (index > (*pte)->index) {
				s.push_back(selem<INDEX, DATA>(pte, R));
				pte=&((*pte)->rchild);
			}
			else {
				break;
			}
		}
		if (*pte == nullptr) {
			return false;
		}

		if ((*pte)->lchild==nullptr && (*pte)->rchild==nullptr) {
			removeleaf(pte, s);
		}
		else if ((*pte)->lchild==nullptr && (*pte)->rchild!=nullptr) {
			removeleaf(pte, s);
		}
		else if ((*pte)->lchild!=nullptr && (*pte)->rchild==nullptr) {
			removeleaf(pte, s);
		}
		else {
			removenonleaf(pte, s);
		}

		return true;
	}


	DATA & operator [](INDEX index) {
		tnode<INDEX, DATA> *ptn=root;
		while (ptn != nullptr) {
			if (index < ptn->index) {
				ptn=ptn->lchild;
			} else if (index > ptn->index) {
				ptn=ptn->rchild;
			} else {
				break;
			}
		}

		if (ptn==nullptr) {
			return _temp;
		} else {
			return ptn->data;
		}
	}

private:
	void __destroy(tnode<INDEX, DATA> *p) {
		if (p!=nullptr) {
			__destroy(p->lchild);
			__destroy(p->rchild);
			delete p;
		}
	}

	void inorderTraverse(tnode<INDEX, DATA> *p) {
		if (p!=nullptr) {
			inorderTraverse(p->lchild);
			cout << p->data << " ";
			inorderTraverse(p->rchild);
		}
	}
	void preorderTraverse(tnode<INDEX, DATA> *p) {
		if (p!=nullptr) {
			cout << p->data << " ";
			preorderTraverse(p->lchild);
			preorderTraverse(p->rchild);
		}
	}
	void postorderTraverse(tnode<INDEX, DATA> *p) {
		if (p!=nullptr) {
			postorderTraverse(p->lchild);
			postorderTraverse(p->rchild);
			cout << p->data << " ";
		}
	}
	void layerorderTraverse(tnode<INDEX, DATA> *p) {
		queue< tnode<INDEX, DATA> * > q;
		q.push(p);
		while (!q.empty()) {
			tnode<INDEX, DATA> *temp=q.front();
			q.pop();
			cout << temp->data << " ";
			if (temp->lchild!=nullptr) {
				q.push(temp->lchild);
			}
			if (temp->rchild!=nullptr) {
				q.push(temp->rchild);
			}
		}
	}
	int height(tnode<INDEX, DATA> *p) {
		if (p==nullptr) {
			return 0;
		} else {
			/*if (p->lchild==nullptr && p->rchild==nullptr) {
				return 1;
			} else if (p->lchild==nullptr && p->rchild!=nullptr) {
				return p->rchild->height+1;
			} else if (p->rchild==nullptr && p->lchild!=nullptr) {
				return p->lchild->height+1;
			} else {
				return MAX(p->lchild->height, p->rchild->height)+1;
			}*/
			return p->height;
		}
	}

	void refresh_height(tedge<INDEX, DATA> *_pte, deque< selem<INDEX, DATA> > &s, INDEX index) {
		tedge<INDEX, DATA> *pte=_pte;
		selem<INDEX, DATA> tse;
		while (!s.empty()) {
			tse=s.back();
			s.pop_back();
			pte=tse.pte;
			(*pte)->height=MAX(height((*pte)->lchild), height((*pte)->rchild))+1;
			int leftheight=height((*pte)->lchild);
			int rightheight=height((*pte)->rchild);
			cout << "Index: " << (*pte)->index 
				<< " Height: " << (*pte)->height 
				<< " Leftheight: " << leftheight 
				<< " Rightheight: " << rightheight << endl;
			if (leftheight - rightheight >= 2) {
				//L
				cout << "The L condition! " << endl;
				tedge<INDEX, DATA> *lpte=&((*pte)->lchild);
				if (index < (*lpte)->index) {
					//LL
					cout << "The LL condition! " << endl;
					R_Rotate((*pte));
					//
					break;
				} else {
					//LR
					cout << "The LR condition! " << endl;
					LR_Rotate((*pte));
					//
					break;
				}
			} 
			else if (leftheight - rightheight <= -2) {
				//R
				cout << "The R condition! " << endl;
				tedge<INDEX, DATA> *rpte=&((*pte)->rchild);
				if (index < (*rpte)->index) {
					//RL
					cout << "The RL condition! " << endl;
					RL_Rotate((*pte));
					//
					break;
				} else {
					//RR
					cout << "The RR condition! " << endl;
					L_Rotate((*pte));
					//
					break;
				}
			}
			else if (leftheight - rightheight == 0) {
				cout << "Equalled! Break! " << endl;
				break;
			} else {
				cout << "Continued! " << endl;
				continue;
			}

		}
	}

	tnode<INDEX, DATA> * L_Rotate(tnode<INDEX, DATA> *&ptn) {
		tnode<INDEX, DATA> *p=ptn;
		ptn=ptn->rchild;
		p->rchild=ptn->lchild;
		ptn->lchild=p;

		p->height=MAX(height(p->lchild), height(p->rchild))+1;
		ptn->height=MAX(height(ptn->lchild), height(ptn->rchild))+1;

		return ptn;
	}

	tnode<INDEX, DATA> * R_Rotate(tnode<INDEX, DATA> *&ptn) {
		tnode<INDEX, DATA> *p=ptn;
		ptn=ptn->lchild;
		p->lchild=ptn->rchild;
		ptn->rchild=p;

		p->height=MAX(height(p->lchild), height(p->rchild))+1;
		ptn->height=MAX(height(ptn->lchild), height(ptn->rchild))+1;

		return ptn;
	}

	tnode<INDEX, DATA> * LR_Rotate(tnode<INDEX, DATA> *&ptn) {
		ptn->lchild=L_Rotate(ptn->lchild);
		return R_Rotate(ptn);
	}

	tnode<INDEX, DATA> * RL_Rotate(tnode<INDEX, DATA> *&ptn) {
		ptn->rchild=R_Rotate(ptn->rchild);
		return L_Rotate(ptn);
	}

	tedge<INDEX, DATA> * findleftmost(tnode<INDEX, DATA> *&ptn) {
		if (ptn==nullptr) {
			return nullptr;
		}
		else {
			tedge<INDEX, DATA> *result=&ptn;
			while ((*result)->lchild!=nullptr) {
				result=&((*result)->lchild);
			}
			return result;
		}
	}

	tedge<INDEX, DATA> * findrightmost(tnode<INDEX, DATA> *&ptn) {
		if (ptn==nullptr) {
			return nullptr;
		}
		else {
			tedge<INDEX, DATA> *result=&ptn;
			while((*result)->rchild!=nullptr) {
				result=&((*result)->rchild);
			}
			return result;
		}
	}

	void swap(tedge<INDEX, DATA> *a, tedge<INDEX, DATA> *b) {
		INDEX itemp;
		DATA dtemp;
		itemp=(*a)->index;
		dtemp=(*a)->data;
		(*a)->index=(*b)->index;
		(*a)->data=(*b)->data;
		(*b)->index=itemp;
		(*b)->data=dtemp;
	}

	void removeleaf(tedge<INDEX, DATA> *pte, deque< selem<INDEX, DATA> > &s) {
		cout << "Removing leaf " << (*pte)->data << endl;
		tnode<INDEX, DATA> *temppp=(*pte);

		(*pte)=((*pte)->lchild!=nullptr) ? ((*pte)->lchild) : ((*pte)->rchild);
		delete (temppp);
		cout << "Successfully deleted! " << endl;

		tedge<INDEX, DATA> *temppte;
		while (!s.empty()) {
			temppte=s.back().pte;
			s.pop_back();
			cout << "Poped! " << endl;
			(*temppte)->height=MAX(height((*temppte)->lchild), height((*temppte)->rchild))+1;
			cout << "Height refreshed! " << endl;

			int leftheight=height((*temppte)->lchild);
			int rightheight=height((*temppte)->rchild);
			cout << "Got leftheight and rightheight! " << endl;

			/*cout << "Refreshing the height of " << (*temppte)->index
				<< " Height: " << (*temppte)->height
				<< " Leftchild: " << (*temppte)->lchild->data << " Leftheight: " << leftheight
				<< " Rightchild: " << (*temppte)->rchild->data << " Rightheight: " << rightheight << endl;
				*/
			if (leftheight - rightheight >= 2) {
				//L
				tedge<INDEX, DATA> *temppteleft=&((*temppte)->lchild);
				if (height((*temppteleft)->lchild) > height((*temppteleft)->rchild)) {
					//LL
					cout << "Removing, the LL condition" << endl;
					R_Rotate((*temppte));
					break;
				}
				else {
					//LR
					cout << "Removing, the LR condition" << endl;
					LR_Rotate((*temppte));
					break;
				}

			} 
			else if (leftheight - rightheight <= -2) {
				//R
				tedge<INDEX, DATA> *temppteright=&((*pte)->rchild);
				if (height((*temppteright)->lchild) > height((*temppteright)->rchild)) {
					//RL
					cout << "Removing, the RL condition" << endl;
					RL_Rotate((*temppte));
					break;
				}
				else {
					//RR
					cout << "Removing, the RR condition" << endl;
					L_Rotate((*temppte));
					break;
				}
			}
			else if ((*temppte)->height==0) {
				break;
			}
			else {
				continue;
			}
		}
	}

	void removenonleaf(tedge<INDEX, DATA> *pte, deque< selem<INDEX, DATA> > &s) {
		if (height((*pte)->lchild) > height((*pte)->rchild)) {
			tedge<INDEX, DATA> *rightmoste=findrightmost((*pte)->lchild);
			swap(rightmoste, pte);
			removeleaf(rightmoste, s);
		}
		else {
			tedge<INDEX, DATA> *leftmoste=findleftmost((*pte)->rchild);
			swap(leftmoste, pte);
			removeleaf(leftmoste, s);
		}
	}



};

int main() {
	BSTree<int, int> bst;
	bst.insert(3, 3);
	bst.insert(2, 2);
	bst.insert(1, 1);
	bst.insert(4, 4);
	bst.insert(5, 5);
	bst.insert(6, 6);
	bst.insert(7, 7);
	bst.insert(10, 10);
	bst.insert(9, 9);
	bst.insert(8, 8);

	bst.remove(4);
	//bst.remove(5);

	/*bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);*/

	cout << bst[6] << endl;
	cout << bst[8] << endl;
	cout << bst[9] << endl;


	bst.show();

	return 0;

}