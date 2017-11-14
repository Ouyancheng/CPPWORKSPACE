#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n,from,to;
	char temp;
	while (cin >> n >> temp >> from >> temp >> to) {
		if (from==to) {
			cout << 0 << endl;
		} else {
			cout << (int)pow(2,n)-1 << endl;
		}
	}
	
	
	return 0;
}
