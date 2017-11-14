/*
 * Huffman.h
 *
 *  Created on: Aug 8, 2016
 *      Author: ouyan
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_
#include "Node.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "Code_Table.h"

ifstream fin;
ofstream fout;
ifstream ifs;
ofstream ofs;
ofstream flog;

static bool compare(cnode a, cnode b) {
	if (a.count < b.count) {
		return true;
	} else {
		return false;
	}
}

static void ReadString(string& str) {
	fin.open("in.txt");
	if (fin.fail()) {
		exit(0);
	}
	char temp;
	temp = fin.get();
	while (temp != EOF) {
		str = str + temp;
		temp = fin.get();
	}
	fin.close();
}

static void QueueGenerator(int a[256], const string& str, Linklist& l) {
	for (int i = 0; i < 256; i++) {
		a[i] = 0;
	}
	for (unsigned int i = 0; i < str.size(); i++) {
		++a[(int) (str[i])];
	}
	vector<cnode> b;
	for (int i = 0; i < 256; i++) {
		if (a[i] > 0) {
			cnode cn;
			cn.c = (char) (i);
			cn.count = a[i];
			b.push_back(cn);
		}
	}
	sort(b.begin(), b.end(), compare);
	flog.open("log.txt");
	for (unsigned int i = 0; i < b.size(); i++) {
		clog << b[i].c << " " << b[i].count << endl;
		flog << b[i].c << " " << b[i].count << endl;
		qnode qn;
		qn.count = b[i].count;
		qn.ispointer = false;
		qn.data.c = b[i].c;
		l.push_back(qn);
	}
	flog.close();
}

static void HuffmanTreeGenerator(Linklist &l) {
	flog.open("log.txt", ios::app | ios::ate);
	while (l.getLength() > 1) {
		qnode a, b;
		a = l.pop_head();
		b = l.pop_head();

		tnode *p;
		tnode *left;
		tnode *right;

		if (a.ispointer == false) {
			left = new tnode;
			left->ispointer = a.ispointer;
			left->data = a.data;
			left->count = a.count;
			left->lchild = NULL;
			left->rchild = NULL;
		} else {
			left = a.data.p;
		}
		if (b.ispointer == false) {
			right = new tnode;
			right->ispointer = b.ispointer;
			right->data = b.data;
			right->count = b.count;
			right->lchild = NULL;
			right->rchild = NULL;
		} else {
			right = b.data.p;
		}

		p = new tnode;

		p->ispointer = true;
		p->lchild = left;
		p->rchild = right;
		p->count = a.count + b.count;

		clog << "Combined two nodes: "
				<< (left->ispointer ? '#' : (left->data.c)) << " "
				<< (right->ispointer ? '#' : (right->data.c)) << endl;
		clog << "The weight of the combined node is " << p->count << endl;

		flog << "Combined two nodes: "
				<< (left->ispointer ? '#' : (left->data.c)) << " "
				<< (right->ispointer ? '#' : (right->data.c)) << endl;
		flog << "The weight of the combined node is " << p->count << endl;
		//p->data.p=NULL;

		qnode q;
		q.count = p->count;
		q.ispointer = true;
		q.data.p = p;
		l.insert(q);
		clog << "Inserted one node! Length: " << l.getLength() << endl;
		flog << "Inserted one node! Length: " << l.getLength() << endl;
	}
	flog.close();
}

static void InorderTraverse(tnode *p) {
	if (p != NULL) {
		InorderTraverse(p->lchild);
		if (p->ispointer == true) {
			cout << p->count << "#" << " ";
		} else {
			cout << p->count << p->data.c << " ";
		}

		InorderTraverse(p->rchild);
	}

	return;
}

static void CodeTableGenerator(tnode *p, string str, string bit) {
	if (p != NULL) {
		str = str.append(bit);

		CodeTableGenerator(p->lchild, str, "0");

		if (p->ispointer == false) {
			codearray[(int) p->data.c] = str;
			fout << (int) p->data.c << " " << str << endl;
			cout << p->data.c << " " << str << endl;
		}

		CodeTableGenerator(p->rchild, str, "1");

		str = str.substr(0, str.size() - 1);
	}

	return;
}

static void CodeTableGenerator_begin(tnode *p, string str) {
	if (p != NULL) {
		CodeTableGenerator(p->lchild, str, "0");
		if (p->ispointer == false) {
			codearray[(int) p->data.c] = str;
			fout << (int) p->data.c << " " << str << endl;
			cout << p->data.c << " " << str << endl;
		}
		CodeTableGenerator(p->rchild, str, "1");
	}

	return;
}

static void CodeGenerator(string str) {
	ofs.open("out2.txt");
	for (unsigned int i = 0; i < str.size(); i++) {
		ofs << codearray[(int) str[i]];
		cout << codearray[(int) str[i]];
	}
	ofs.close();
}

static void Decoder(string str, tnode *root) {
	ofs.open("out3.txt");
	tnode *p;
	p = root;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (p == NULL) {
			p = root;
			continue;
		}
		if (p->ispointer == false) {
			ofs << (char) p->data.c;
			p = root;
		}
		if (str[i] == '0') {
			p = p->lchild;
		} else if (str[i] == '1') {
			p = p->rchild;
		}
	}
	ofs.close();
}
#endif /* HUFFMAN_H_ */
