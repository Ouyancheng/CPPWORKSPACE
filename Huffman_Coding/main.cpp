/*
 * main.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: ouyan
 */

#include "Linklist.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Huffman.h"
using namespace std;


void DeleteTree(tnode *p);






extern ofstream fout;
extern ifstream fin;

int main() {
	int a[256];
	Linklist l;

	string str;
	//cin >> str;
	ReadString(str);

	QueueGenerator(a, str, l);

	HuffmanTreeGenerator(l);


	tnode *root;
	root=l.pop_head().data.p;

	InorderTraverse(root);
	cout << endl;

	fout.open("out.txt");
	CodeTableGenerator_begin(root, string());
	fout << endl;
	fout.close();

	CodeGenerator(str);

	fin.open("out2.txt");
	string code;
	fin >> code;
	fin.close();

	Decoder(code, root);

	DeleteTree(root);
	return 0;
}

void DeleteTree(tnode *p) {
	if (p!=NULL) {
		DeleteTree(p->lchild);
		DeleteTree(p->rchild);
		delete p;
	}
}
