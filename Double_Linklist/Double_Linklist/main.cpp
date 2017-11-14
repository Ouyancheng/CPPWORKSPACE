#include "Linklist.hpp"
#include "main.h"
#include <cstdlib>
using namespace std;
int main() {
	Test();
	system("pause");
	return 0;
}

void Test() {
	Linklist<int> ll;
	ll.push_back(3);
	ll.push_back(2);
	ll.push_back(1);
	ll.push_front(6);
	ll.push_front(8);
	ll.push_front(9);

	ll.insert(9, 0);
	ll.insert(10, 3);

	ll.show();
	ll.reverse();
	ll.show();

	cout << ll.middle() << endl;

	for (unsigned int i = 0; i < ll.size(); i++) {
		cout << ll[i] << " ";
	}
	cout << endl;

	ll.show();
	ll.rshow();
	cout << endl;

	ll.remove(2);

	ll.show();
	ll.rshow();
	cout << endl;

	cout << ll.pop_back() << endl;
	cout << ll.pop_front() << endl;
	cout << endl;

	ll.show();
	ll.rshow();
	cout << endl;

	ll.reverse();

	for (unsigned int i = 0; i < ll.size(); i++) {
		cout << ll[i] << " ";
	}
	cout << endl;
}
