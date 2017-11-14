#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <algorithm>
#include <fstream>
#define S 1048576
using namespace std;

int main() {
	ofstream ofs;

	ofs.open("Test.txt");
	vector<int> v;
	//v.push_back(0);
	for (int i=0;i<S;i++) {
		v.push_back(S-i);
		//printf("%d ", (&v[0]+i));
		ofs << &v[0]+i << endl;
	}
	ofs.close();
	//sort(&v[0], &v[v.size()-1]+1);

	/*for (int i=0;i<v.size();i++) {
		printf("%d ", (&v[0]+i));
	}*/
	system("pause");
	return 0;
}