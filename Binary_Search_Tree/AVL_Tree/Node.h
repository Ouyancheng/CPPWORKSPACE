#pragma once
#ifndef EH
#define EH 0
#endif // !EH

#ifndef LH
#define LH 1
#endif // !LH

#ifndef RH
#define RH -1
#endif // !RH


enum position { left, right, undefined };
struct tnode
{
	int data;
	int bf;
	
	tnode *parent;
	position frompos;

	tnode *lchild;
	tnode *rchild;

	tnode(int data, tnode *parent = nullptr, position frompos = position::undefined)
		: data(data), bf(EH), parent(parent), frompos(frompos), lchild(nullptr), rchild(nullptr)
	{

	}
};



struct snode
{
	tnode *p;
	position pos;

	snode(tnode *p = nullptr, position pos = position::undefined)
		: p(p), pos(pos)
	{

	}

	snode(const snode &another)
		: p(another.p), pos(another.pos)
	{
		
	}
};
