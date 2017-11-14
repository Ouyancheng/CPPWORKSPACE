#include <iostream>
using namespace std;
int main() {
	unsigned long long int i;
	int *p;
	int a=10;
	p=&a;
	cout << p << endl;
	cout << (unsigned long long)p << endl;

	i=(unsigned long long)p;
	cout << *((int *)i) << endl;

	return 0;
}