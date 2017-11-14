#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,f,t;
	char temp;
	while (cin >> n >> temp >> f >> temp >> t) {
		if (f==t) {
			cout << (int)0 << endl;
		} else {
			cout << (int)pow(2,n)-1 << endl;
		}
	}
	return 0;
}
