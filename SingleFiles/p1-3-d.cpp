#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, x, y;
	char c;
	while (cin >> n >> c >> x >> c >> y) {
		if (x==y) {
			cout << "0" << endl;
		}
		else {
			cout << (int)pow(2,n)-1 << endl;
		}
	}
	return 0;
}
