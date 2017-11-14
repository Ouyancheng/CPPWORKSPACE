#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	int n;
	fstream ifs;
	stringstream ss;
	ifs.open("decDump.txt", ios::in|ios::out);
	while (!ifs.eof()) {
		ifs >> n;
		// cout << n << endl;
		// fprintf(output, "%#010x\n", n);
		printf("%-18d", n);
		printf("%#010x\n", n);
	}
	return 0;
}