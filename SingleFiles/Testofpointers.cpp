#include <iostream>
#include <stack>
using namespace std;
struct node {
	int a;
	int b;
	int c;
};

int main() {
	stack <node **> s;
	node n;
	n.a=10;
	n.b=20;
	n.c=30;
	node n2;
	n2.a=60;
	n2.b=80;
	n2.c=90;

	node **pp;
	node *p;
	p=&n;
	pp=&p;
	s.push(&p);
	p=&n2;

	cout << (*s.top())->b << endl;

	return 0;
}