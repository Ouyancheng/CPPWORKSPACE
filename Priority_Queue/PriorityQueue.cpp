/*
 * PriorityQueue.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	// TODO Auto-generated constructor stub
	root = leftmost = NULL;
	length = 0u;
}

PriorityQueue::~PriorityQueue()
{
	// TODO Auto-generated destructor stub
	deleteNode(root);
}

void PriorityQueue::insert(int data)
{
	if (root == NULL)
	{
		root = new qnode(data, NULL);
		leftmost = root;
		++length;
	}
	else
	{
		qnode *p;
		qnode *pre;
		p = root;
		bool turnedright = false;

		enum position
		{
			left, right
		} pos;

		while (p != NULL)
		{
			if (data <= p->data)
			{
				pre = p;
				p = p->lchild;
				pos = left;
			}
			else
			{
				pre = p;
				p = p->rchild;
				pos = right;
				turnedright = true;
			}
		}
		if (pos == left)
		{
			pre->lchild = new qnode(data, pre);
			p = pre->lchild;
		}
		else
		{
			pre->rchild = new qnode(data, pre);
			p = pre->rchild;
		}

		++length;
		if (!turnedright)
		{
			leftmost = p;
		}
	}
}

int PriorityQueue::pop_smallest()
{
	if (length == 0u)
	{
		return 0;
	}

	if (leftmost->rchild == NULL)
	{
		int result = leftmost->data;

		qnode *p = leftmost->parent;
		/*while (p->lchild!=leftmost) {
		 p=p->lchild;
		 }*/
		if (leftmost == root)
		{
			root = NULL;
		}

		delete leftmost;
		leftmost = p;
		if (leftmost != NULL)
		{
			leftmost->lchild = NULL;
		}
		--length;
		return result;

	}
	else
	{
		int result = leftmost->data;

		qnode *p = leftmost->parent;
		/*while (p->lchild!=leftmost) {
		 p=p->lchild;
		 }*/
		if (leftmost == root)
		{
			root = leftmost->rchild;
			root->parent = NULL;
			delete leftmost;
			leftmost = root;

		}
		else
		{
			p->lchild = leftmost->rchild;
			leftmost->rchild->parent = p;
			p = p->lchild;
			while (p->lchild != NULL)
			{
				p = p->lchild;
			}
			delete leftmost;
			leftmost = p;
		}

		--length;
		return result;
	}
}

void PriorityQueue::InorderTraverse(qnode *p)
{
	if (p != NULL)
	{
		InorderTraverse(p->lchild);
		cout << p->data << " ";
		InorderTraverse(p->rchild);
	}

	return;
}

void PriorityQueue::PreorderTraverse(qnode *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		PreorderTraverse(p->lchild);
		PreorderTraverse(p->rchild);
	}

	return;
}

void PriorityQueue::PostorderTraverse(qnode *p)
{
	if (p != NULL)
	{
		PostorderTraverse(p->lchild);
		PostorderTraverse(p->rchild);
		cout << p->data << " ";
	}
}

qnode *PriorityQueue::getRoot()
{
	return root;
}

qnode *PriorityQueue::getLeftmost()
{
	return leftmost;
}

int PriorityQueue::getLength()
{
	return length;
}

void PriorityQueue::deleteNode(qnode *p)
{
	if (p != NULL)
	{
		deleteNode(p->lchild);
		deleteNode(p->rchild);
		delete p;
	}

	return;
}
