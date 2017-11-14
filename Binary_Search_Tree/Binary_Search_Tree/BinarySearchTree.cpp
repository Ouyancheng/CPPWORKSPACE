#include "BinarySearchTree.h"
#ifndef NODEPTR
#define NODEPTR node *
#endif // !NODEPTR

inline void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	size = 0u;
}


BinarySearchTree::~BinarySearchTree()
{
	deleteTree(root);
	root = nullptr;
}

void BinarySearchTree::deleteTree(node *p)
{
	if (p != nullptr)
	{
		deleteTree(p->lchild);
		deleteTree(p->rchild);
		delete p;
	}
}

void BinarySearchTree::insertElement(int element)
{
	if (root == nullptr)
	{
		root = new node(element);
		++size;
		return;
	}

	node *p = root;
	node *pre = root;
	position pos;

	while (p != nullptr)
	{
		if (element <= p->data)
		{
			pre = p;
			p = p->lchild;
			pos = position::left;
		}
		else
		{
			pre = p;
			p = p->rchild;
			pos = position::right;
		}
	}

	if (pos == position::left)
	{
		pre->lchild = new node(element);
	}
	else
	{
		pre->rchild = new node(element);
	}
	++size;
}

int BinarySearchTree::popMinElement()
{
	node *p = root;
	node *pre = nullptr;
	int result = 0;

	if (p == nullptr)
	{
		return 0;
	}

	while (p->lchild != nullptr)
	{
		pre = p;
		p = p->lchild;
	}

	if (p == root)
	{
		if (p->rchild == nullptr)
		{
			result = p->data;
			delete p;
			root = nullptr;
		}
		else
		{
			root = root->rchild;
			result = p->data;
			delete p;
		}
	}
	else
	{
		if (p->rchild == nullptr)
		{
			pre->lchild = nullptr;
			result = p->data;
			delete p;
		}
		else
		{
			pre->lchild = p->rchild;
			result = p->data;
			delete p;
		}
	}
	--size;
	return result;
}

int BinarySearchTree::popMaxElement()
{
	node *p = root;
	node *pre = nullptr;
	int result = 0;

	if (p == nullptr)
	{
		return 0;
	}

	while (p->rchild != nullptr)
	{
		pre = p;
		p = p->rchild;
	}

	if (p == root)
	{
		if (p->lchild == nullptr)
		{
			root = nullptr;
			result = p->data;
			delete p;
		}
		else
		{
			root = p->lchild;
			result = p->data;
			delete p;
		}
	}
	else
	{
		if (p->lchild == nullptr)
		{
			pre->rchild = nullptr;
			result = p->data;
			delete p;
		}
		else
		{
			pre->rchild = p->lchild;
			result = p->data;
			delete p;
		}
	}
	--size;
	return result;
}

bool BinarySearchTree::deleteElement(int element)
{
	node *p = root;
	node *pre = root;
	enum position { left, right } pos;
	while (p != nullptr)
	{
		if (element < p->data)
		{
			pre = p;
			pos = position::left;
			p = p->lchild;
		}
		else if (element > p->data)
		{
			pre = p;
			pos = position::right;
			p = p->rchild;
		}
		else
		{
			break;
		}
	}

	if (p == nullptr)
	{
		return false;
	}

	if (p->lchild == nullptr && p->rchild == nullptr)
	{
		if (p == root)
		{
			root = nullptr;
			delete p;
			return true;
		}
		if (pos == position::left)
		{
			pre->lchild = nullptr;
		}
		else
		{
			pre->rchild = nullptr;
		}
		delete p;
		return true;
	}
	else if (p->lchild == nullptr && p->rchild != nullptr)
	{
		if (p == root)
		{
			root = p->rchild;
			delete p;
			return true;
		}
		if (pos == position::left)
		{
			pre->lchild = p->rchild;
		}
		else
		{
			pre->rchild = p->rchild;
		}
		delete p;
		return true;
	}
	else if (p->lchild != nullptr && p->rchild == nullptr)
	{
		if (p == root)
		{
			root = p->lchild;
			delete p;
			return true;
		}
		if (pos == position::left)
		{
			pre->lchild = p->lchild;
		}
		else
		{
			pre->rchild = p->lchild;
		}
		delete p;
		return true;
	}
	else
	{
		node *q = p->lchild;
		node *qpre = p;
		//position qpos;
		while (q->rchild != nullptr)
		{
			qpre = q;
			q = q->rchild;
		}

		if (qpre == p)
		{
			swap(q->data, p->data);
			p->lchild = q->lchild;
			delete q;
			return true;
		}
		else
		{
			swap(q->data, p->data);
			qpre->rchild = q->lchild;
			delete q;
			return true;
		}

	}
}

void BinarySearchTree::inorderTraverse(node *p)
{
	if (p != nullptr)
	{
		inorderTraverse(p->lchild);
		cout << p->data << " ";
		inorderTraverse(p->rchild);
	}
}

void BinarySearchTree::inorderTraverse()
{
	stack< node * > Stack;
	node *p = root;

	if (p == nullptr)
	{
		cout << "The tree is empty! " << endl;
		return;
	}

	while (p != nullptr || !Stack.empty())
	{
		while (p != nullptr)
		{
			Stack.push(p);
			p = p->lchild;
		}
		p = Stack.top();
		Stack.pop();
		cout << p->data << " ";
		p = p->rchild;
	}
	cout << endl;
}

void BinarySearchTree::preorderTraverse(node *p)
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraverse(p->lchild);
		preorderTraverse(p->rchild);
	}
}

void BinarySearchTree::preorderTraverse()
{
	stack< node * > Stack;
	node *p = root;
	if (p == nullptr)
	{
		cout << "The tree is empty! " << endl;
		return;
	}
	while (p != nullptr || !Stack.empty())
	{
		while (p != nullptr)
		{
			Stack.push(p);
			cout << p->data << " ";
			p = p->lchild;
		}
		p = Stack.top();
		Stack.pop();
		p = p->rchild;
	}
	cout << endl;
}

void BinarySearchTree::postorderTraverse(node *p)
{
	if (p != nullptr)
	{
		postorderTraverse(p->lchild);
		postorderTraverse(p->rchild);
		cout << p->data << " ";
	}
}

void BinarySearchTree::postorderTraverse()
{
	//postorderTraverse(root);
	//cout << endl;

	enum tagtype { left, right };
	struct stacknode
	{
		node *p;
		tagtype tag;

		stacknode(node *p = nullptr, tagtype tag = left)
			: p(p), tag(tag)
		{
		}
	};

	stack< stacknode > Stack;
	stacknode temp;
	node *p = root;

	do
	{
		while (p != nullptr)
		{
			//temp.p = p;
			//temp.tag = tagtype::left;
			Stack.push(stacknode(p, tagtype::left));
			p = p->lchild;
		}

		while (!Stack.empty() && Stack.top().tag == tagtype::right)
		{
			temp = Stack.top();
			Stack.pop();
			p = temp.p;
			cout << p->data << " ";
		}

		if (!Stack.empty())
		{
			Stack.top().tag = tagtype::right;
			p = Stack.top().p->rchild;
		}
	} while (!Stack.empty());

	cout << endl;
}

void BinarySearchTree::layerTraverse()
{
	std::queue< node * > q;
	q.push(root);

	node *p;
	while (!q.empty())
	{
		p = q.front();
		cout << p->data << " ";
		q.pop();
		if (p->lchild != nullptr)
		{
			q.push(p->lchild);
		}
		if (p->rchild != nullptr)
		{
			q.push(p->rchild);
		}
	}
	cout << endl;
}


bool BinarySearchTree::searchElement(int element)
{
	node *p = root;
	if (p == nullptr)
	{
		return false;
	}

	while (p != nullptr)
	{
		if (element < p->data)
		{
			p = p->lchild;
		}
		else if (element > p->data)
		{
			p = p->rchild;
		}
		else
		{
			break;
		}
	}

	if (p != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BinarySearchTree::LRotate(node *&p)
{
	node *temp;
	temp = p;
	p = p->rchild;
	temp->rchild = p->lchild;
	p->lchild = temp;
}

void BinarySearchTree::RRotate(node *&p)
{
	node *temp;
	temp = p;
	p = p->lchild;
	temp->lchild = p->rchild;
	p->rchild = temp;
}

unsigned int BinarySearchTree::getHeight(node *p)
{
	if (p == nullptr)
	{
		return 0u;
	}
	else
	{
		return MAX(getHeight(p->lchild), getHeight(p->rchild)) + 1;
	}
}

unsigned int BinarySearchTree::getSize()
{
	return size;
}

node * BinarySearchTree::getRoot()
{
	return root;
}
