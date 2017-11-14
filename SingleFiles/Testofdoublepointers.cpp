#include <iostream>
using namespace std;
struct node
{
	int **pptr;
	int id;
};
int main() {
	int a = 10;
	int *pa = &a;
	int **pp = &pa;
	int b = 20;
	int *pb = &b;
	int **ppt2=&pb;

	int **ppt = pp;
	node n;
	n.pptr=ppt;
	ppt=ppt2;



	//ppt2 = &pb;
	//*ppt = pb;

	cout << ppt << " " << *ppt << " " << **ppt << endl;
	//cout << ppt2 << " " << *ppt2 << " " << **ppt2 << endl;
	cout << n.pptr << " " << *n.pptr << " " << **n.pptr << endl;

	return 0;
}