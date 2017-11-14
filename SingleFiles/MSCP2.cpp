#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std; 

struct node {
	char from;
	char to;
	
	node(char from, char to) : from(from), to(to) {
		
	}
};

int main() {
	string map;
	string sen;
	vector<node> a;
	
	bool exist=false;
	
	char tfrom='\0', tto='\0';
	while (getline(cin, map)) {
		getline(cin, sen);
		a.clear();
		for (unsigned int i=0;i<map.size();i++) {
			if (tfrom=='\0') {
				tfrom=map[i];
				++i;
			} else {
				tto=map[i];
				++i;
				a.push_back(node(tfrom, tto));
				tfrom='\0';
			}
		}
		
		/*for (int i=0;i<a.size();i++) {
			cout << a[i].from << "-" << a[i].to << " ";
		}
		cout << endl;*/
		
		for (unsigned int i=0;i<sen.size();i++) {
			exist=false;
			for (unsigned int j=0;j<a.size();j++) {
				if (toupper(a[j].from)==sen[i]) {
					cout << (char)toupper(a[j].to);
					exist=true;
					break;
				} else if (tolower(a[j].from)==sen[i]) {
					cout << (char)tolower(a[j].to);
					exist=true;
					break;
				}
			}
			
			if (!exist) {
				cout << sen[i];
			}
		}
		
	} 
	
	return 0;
}
