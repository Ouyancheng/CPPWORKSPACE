#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

bool isvalid(char c) {
	if (c>='A' && c<='F') {
		return true;
	} else if (c>='0' && c<='9') {
		return true;
	} else {
		return false;
	}
}
int main() {
	string a;
	bool valid=true;
	while (getline(cin, a)) {
		valid=true;
		
		char c;
		for (unsigned int i=0; i<a.size(); i++) {
			if (a[i]=='\\') {
				c=a[i+1];
				if (!isvalid(c)) {
					cout << "CORRUPTED" << endl;
					valid=false;
					break;
				}
				if (a[i+2]=='\\') {
					cout << "CORRUPTED" << endl;
					valid=false;
					break;
				}
			}
			else if (!isvalid(a[i])) {
				cout << "CORRUPTED" << endl;
				valid=false;
				break;
			}
		}
		if (!valid) {
			continue;
		}
		for (unsigned int i=0; i<a.size(); i++) {
			if (a[i]=='\\') {
				c = a[i+1];
				if (isvalid(c)) {
					cout << a[i+2] << a[i+2] << a[i+2];
					if (isdigit(c)) {
						for (int j=0; j < c-'0'; j++) {
							cout << a[i+2];
						}
					} else if (isalpha(c)) {
						for (int j=0; j<10; j++) {
							cout << a[i+2];
						}
						for (int j=0; j< c-'A'; j++) {
							cout << a[i+2];
						}
					}
					i+=2;
				}
			} else {
				cout << a[i];
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
