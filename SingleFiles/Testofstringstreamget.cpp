#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	stringstream ss;
	string s;
	cin >> s;
	ss << s;
	cout << (char)ss.get() << endl;
	cout << (char)ss.get() << endl;
	cout << (char)ss.get() << endl;

	cout << ss.str() << endl;
	cout << s << endl;

	system("pause");

	return 0;
}