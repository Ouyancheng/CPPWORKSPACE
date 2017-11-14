#include <stdio.h>

struct childnode
{
	int childindex;
	struct childnode *next;
};

struct treenode
{
	char data;
	int parentindex;
	struct childnode *firstchild;
};

struct tree
{
	treenode *base;  //The base pointer refers to an array of tree node
	int root;
	int size;
};



