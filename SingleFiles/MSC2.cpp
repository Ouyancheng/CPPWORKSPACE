#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct mpair {
	char from;
	char to;
	mpair(char from, char to) : from(from), to(to) {
		
	}
};

int main() {
	string map;
	string sen;
	bool found=false;
	vector<mpair> hash;
	
	char tfrom='\0';
	char tto='\0';
	
	while (getline(cin, map)) {
		getline(cin, sen);
		for (unsigned int i=0;i<map.size();i++) {
			if (tfrom=='\0') {
				tfrom=map[i];
				++i;
			} else {
				tto=map[i];
				++i;
				hash.push_back(mpair(tfrom, tto));
				tfrom=tto='\0';
			}
		}
		
		/*for (unsigned int i=0;i<hash.size();i++) {
			cout << (char)hash[i].from << "-" << (char)hash[i].to << " ";
		}*/
		
		for (unsigned int i=0;i<sen.size();i++) {
			found=false;
			for (unsigned int j=0;j<hash.size();j++) {
				if (toupper(hash[j].from)==sen[i]) {
					cout << (char)toupper(hash[j].to);
					found=true;
					break;
				} else if (tolower(hash[j].from)==sen[i]) {
					cout << (char)tolower(hash[j].to);
					found=true;
					break;
				}
			}
			if (found==false) {
				cout << sen[i];
			}
		}
		
		cout << endl;
	}
	
	return 0;
}
