#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool check_valid(const string &str) {
	int left_parenthesis_number = 0;
	for (char c : str) {
		if (c == ')') {
			if (left_parenthesis_number == 0) {
				return false;
			} else {
				--left_parenthesis_number; 
			}
		} else if (c == '(') {
			++left_parenthesis_number;
		}
	}
	// cout << str << endl; 
	printf("%s\n", str.c_str());
	return true;
}
int left_number; 
int right_number; 
void dfs(string &str) {
	if (left_number > 0) {
		str.push_back('(');
		--left_number; 
		dfs(str);
		++left_number; 
		str.pop_back();
	} 

	if (right_number > 0) {
		str.push_back(')');
		--right_number; 
		dfs(str);
		++right_number; 
		str.pop_back();
	} else {
		check_valid(str);
		return; 
	}

}
int main() {
	int n; 
	cin >> n;
	left_number = right_number = n;
	string str;
	dfs(str); 
	return 0;
}