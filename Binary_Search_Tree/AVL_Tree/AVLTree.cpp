#include "AVLTree.h"
#include <cstdlib>
#ifndef MAX
#define MAX(a, b) (((a)>(b))?(a):(b))
#endif // !MAX
#include <climits>

AVLTree::AVLTree()
{
	root = nullptr;
}


AVLTree::~AVLTree()
{
	delSub(root);
}

void AVLTree::delSub(tnode *p)
{
	if (p != nullptr)
	{
		delSub(p->lchild);
		delSub(p->rchild);
		delete p;
	}
}

void AVLTree::InorderTraverse(tnode *p)
{
	if (p != nullptr)
	{
		InorderTraverse(p->lchild);
		cout << p->data << " ";
		InorderTraverse(p->rchild);
	}
}

void AVLTree::PreorderTraverse(tnode *p)
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		PreorderTraverse(p->lchild);
		PreorderTraverse(p->rchild);
	}
}

void AVLTree::PostorderTraverse(tnode *p)
{
	if (p != nullptr)
	{
		PostorderTraverse(p->lchild);
		PostorderTraverse(p->rchild);
		cout << p->data << " ";
	}
}

void AVLTree::LayerTraverse(tnode *p)
{
	queue<tnode *> Queue;
	Queue.push(p);
	
	tnode *temp;
	while (!Queue.empty())
	{
		temp = Queue.front();
		Queue.pop();
		cout << temp->data << " ";
		if (temp->lchild != nullptr)
		{
			Queue.push(temp->lchild);
		}
		if (temp->rchild != nullptr)
		{
			Queue.push(temp->rchild);
		}
	}
}

tnode * AVLTree::getRoot()
{
	return root;
}

int AVLTree::getHeight(tnode *p)
{
	if (p == nullptr)
	{
		return 0u;
	}
	else
	{
		return MAX(getHeight(p->lchild), getHeight(p->rchild));
	}
}

void AVLTree::LRotate(tnode *&p)
{
	tnode *temp;
	temp = p;
	p = p->rchild;
	temp->rchild = p->lchild;
	p->lchild = temp;

	p->bf = getHeight(p->lchild) - getHeight(p->rchild);
	temp->bf = getHeight(temp->lchild) - getHeight(temp->rchild);
}

void AVLTree::RRotate(tnode *&p)
{
	tnode *temp;
	temp = p;
	p = p->lchild;
	temp->lchild = p->rchild;
	p->rchild = temp;

	p->bf = getHeight(p->lchild) - getHeight(p->rchild);
	temp->bf = getHeight(temp->lchild) - getHeight(temp->rchild);
}

bool AVLTree::addElem(int element)
{
	if (root == nullptr)
	{
		root = new tnode(element);
		return true;
	}

	tnode *p = root;
	tnode *pre = nullptr;
	stack<snode> Stack;

	while (p != nullptr)
	{
		if (element < p->data)
		{
			pre = p;
			Stack.push(snode(pre, position::left));
			p = p->lchild;
		}
		else if (element > p->data)
		{
			pre = p;
			Stack.push(snode(pre, position::right));
			p = p->rchild;
		}
		else
		{
			return false;
		}
	}

	if (Stack.top().pos == position::left)
	{
		pre->lchild = new tnode(element, pre, position::left);
	}
	else
	{
		pre->rchild = new tnode(element, pre, position::right);
	}

	
	//cout << "Element added! " << endl;
	//cout << "Pre bf: " << pre->bf << endl;
	//show();
	//system("pause");

	snode tempsn;
	position prepos = undefined;
	position pprepos = Stack.top().pos;

	while (!Stack.empty())
	{
		tempsn = Stack.top();
		Stack.pop();
		pprepos = prepos;
		prepos = tempsn.pos;
		
		if (tempsn.p->bf == EH)
		{
			if (tempsn.pos == position::left)
			{
				++tempsn.p->bf;
			}
			else if (tempsn.pos == position::right)
			{
				--tempsn.p->bf;
			}
			else
			{
				cerr << "Error: Child position undefined EH" << endl;
			}
		}
		else if (tempsn.p->bf == LH)
		{
			//L
			if (tempsn.pos == position::left)
			{
				//LL
				if (pprepos == position::left)
				{
					switch (tempsn.p->frompos)
					{
					case position::left:
						RRotate(tempsn.p->parent->lchild);
						break;
					case position::right:
						RRotate(tempsn.p->parent->rchild);
						break;
					default:
						cerr << "Error: Undefined from position LH LL" << endl;
						break;
					}
					break;
				}
				//LR
				else if (pprepos == position::right)
				{
					switch (tempsn.p->frompos)
					{
					case position::left:
						LRotate(tempsn.p->parent->lchild->lchild);
						RRotate(tempsn.p->parent->lchild);
						break;
					case position::right:
						LRotate(tempsn.p->parent->rchild->lchild);
						RRotate(tempsn.p->parent->rchild);
						break;
					default:
						cerr << "Error: Undefined from position LH LR" << endl;
						break;
					}
					break;
				}
				//!LL !LR
				else
				{
					cerr << "Error: Undefined pre-pre-position LH" << endl;
				}
			}
			//R
			else if (tempsn.pos == position::right)
			{
				--tempsn.p->bf;
				break;
			}
			//!L !R
			else
			{
				cerr << "Error: Undefined position LH" << endl;
			}
		}
		else if (tempsn.p->bf == RH)
		{
			//L
			if (tempsn.pos == position::left)
			{
				++tempsn.p->bf;
				break;
			}
			//R
			else if (tempsn.pos == position::right)
			{
				//RL
				if (pprepos == position::left)
				{
					switch (tempsn.p->frompos)
					{
					case position::left:
						RRotate(tempsn.p->parent->lchild->rchild);
						LRotate(tempsn.p->parent->lchild);
						break;
					case position::right:
						RRotate(tempsn.p->parent->rchild->rchild);
						LRotate(tempsn.p->parent->rchild);
						break;
					default:
						cerr << "Error: Undefined from position RH RL" << endl;
						break;
					}
					break;
				}
				//RR
				else if (pprepos == position::right)
				{
					switch (tempsn.p->frompos)
					{
					case position::left:
						LRotate(tempsn.p->parent->lchild);
						break;
					case position::right:
						RRotate(tempsn.p->parent->rchild);
						break;
					default:
						cerr << "Error: Undefined from position RH RR" << endl;
						break;
					}
					break;
				}
				//!RL !RR
				else
				{
					cerr << "Error: Undefined pre-pre-position RH" << endl;
				}
			}
			//!L !R
			else
			{
				cerr << "Error: Undefined position RH" << endl;
			}
		}
		//!LH !RH !EH
		else
		{
			cerr << "Error: Balance factor not between -1 and 1" << endl;
		}

	}

	return true;
}

void AVLTree::show()
{
	cout << "Layer: " << endl;
	LayerTraverse(root);
	cout << "\nInorder: " << endl;
	InorderTraverse(root);
	cout << "\nPreorder: " << endl;
	PreorderTraverse(root);
	cout << "\nPostorder: " << endl;
	PostorderTraverse(root);
	cout << endl;
	
}