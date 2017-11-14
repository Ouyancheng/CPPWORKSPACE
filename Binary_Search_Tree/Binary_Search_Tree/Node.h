#pragma once
using namespace std;
struct node
{
	int data;
	node *lchild;
	node *rchild;

	node(int data) 
		: data(data), lchild(nullptr), rchild(nullptr)
	{
	}
};

enum position
{
	left,
	right
};

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif // !MAX
