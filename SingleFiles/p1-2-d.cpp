#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct node {
	char from;
	char to;
	node(char f, char t) : from(f), to(t) {
		
	}
};

int main() {
	vector<node> a;
	string token;
	string str;
	
	char from;
	char to;
	
	bool isright=false;
	
	getline(cin, token);
	//cin.get();
	getline(cin, str);
	//cin.get();
	
	for (unsigned int i=0;i<token.size();i++) {
		if (!isright) {
			from=token[i];
			i++;
			isright=true;
		} else {
			to=token[i];
			i++;
			isright=false;
			a.push_back(node(from, to));
		}
	}
	
	/*for (unsigned int i=0;i<a.size();i++) {
		cout << a[i].from << "-" << a[i].to << " ";
	}
	cout << endl;*/
	
	bool found=false;
	for (unsigned int i=0;i<str.size();i++) {
		found=false;
		if (str[i]==' ') {
			cout << " ";
		} else {
			for (unsigned int j=0;j<a.size();j++) {
				if (tolower(a[j].from) == str[i]) {
					cout << (char)tolower(a[j].to);
					found=true;
					break;
				} 
				
				if (toupper(a[j].from) == str[i]) {
					cout << (char)toupper(a[j].to);
					found=true;
					break;
				}
				
			}
			if (!found) {
				cout << str[i];
			}
			
		}
	}
	cout << endl;
	
	return 0;
}
