#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

double parseDouble(string a) {
	stringstream ss;
	ss << a;
	double result = 0;

	ss >> result;

	return result;
}

class RPNnode {
public:
	char c;
	double d;
	bool ischar;

	unsigned int priority() {
		if (ischar==false) {
			return 0u;
		}
		else if (c=='#') { 
			return 1u;
		}
		else if (c=='+' || c=='-') {
			return 2u;
		}
		else if (c=='*' || c=='/' || c=='%') {
			return 3u;
		}
		/*else if (c=='^') {
			return 4u;
		}*/
		else {
			return 0u;
		}
	}

	RPNnode(char c) : c(c), d(0.0), ischar(true) {

	}

	RPNnode(double d) : c('\0'), d(d), ischar(false) {

	}


};

inline bool isOperator(char c) {
	if (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='#' || c=='%') {
		return true;
	}
	else {
		return false;
	}
}

inline bool isNumber(char c) {
	if (c>='0' && c<='9') {
		return true;
	}
	else if (c=='.') {
		return true;
	}
	else {
		return false;
	}
}

unsigned int priority(char c) {
	if (isOperator(c)==false) {
		return 0u;
	}
	else if (c=='#') { 
		return 1u;
	}
	else if (c=='+' || c=='-') {
		return 2u;
	}
	else if (c=='*' || c=='/' || c=='%') {
		return 3u;
	}
	else if (c=='^') {
		return 4u;
	}
	else {
		return 0u;
	}
}

void RPNprocedure(deque<RPNnode> &RPNS, string a) {
	deque<RPNnode> OS;
	OS.push_back(RPNnode('#'));
	for (unsigned int i=0u; i<a.size(); i++) {

		if (isOperator(a[i])) {

			if (a[i]=='(') {
				OS.push_back(RPNnode('('));
			}

			else if (a[i]==')') {

				while (OS.back().c != '(') {
					RPNS.push_back(OS.back());
					OS.pop_back();
				}
				OS.pop_back();
			}

			else if (priority(a[i]) > OS.back().priority()) {
				OS.push_back(RPNnode(a[i]));
			}

			else if (priority(a[i]) <= OS.back().priority()) {

				while (OS.back().priority() >= priority(a[i])) {
					RPNS.push_back(OS.back());
					OS.pop_back();
				}

				OS.push_back(RPNnode(a[i]));
			}

			else {
				continue;
			}
		} 
		else if (isNumber(a[i])) {
			string dstr;
			while (isNumber(a[i])) {
				dstr+=a[i];
				++i;
			}
			--i;
			double d = parseDouble(dstr);
			RPNS.push_back(RPNnode(d));
		}
	}

	while (OS.back().c!='#') {
		RPNS.push_back(OS.back());
		OS.pop_back();
	}

	return;
}

double calculate(deque<RPNnode> &RPNS) {
	//cout << "IN CALCULATION" << endl;
	for (unsigned int i=0;i<RPNS.size();i++) {
		if (RPNS[i].ischar==true) {
			cout << RPNS[i].c << " ";
		}
		else {
			cout << RPNS[i].d << " ";
		}
	}
	cout << endl;
	//return 0.0;
	reverse(RPNS.begin(), RPNS.end());
	deque<double> value;
	value.push_back(0.0);
	value.push_back(0.0);
	while (!RPNS.empty()) {
		if (RPNS.back().ischar == false) {
			value.push_back(RPNS.back().d);
		}
		else if (RPNS.back().ischar == true) {

			double a = 0.0, b = 0.0;
			switch(RPNS.back().c) {
			case '+':
				a = value.back();
				value.pop_back();
				b = value.back();
				value.pop_back();
				value.push_back(b+a);
				break;
			case '-':
				a = value.back();
				value.pop_back();
				b = value.back();
				value.pop_back();
				value.push_back(b-a);
				break;
			case '*':
				a = value.back();
				value.pop_back();
				b = value.back();
				value.pop_back();
				value.push_back(b*a);
				break;
			case '/':
				a = value.back();
				value.pop_back();
				b = value.back();
				value.pop_back();
				value.push_back(b/a);
				break;
			case '%':
				a = value.back();
				value.pop_back();
				b = value.back();
				value.pop_back();
				value.push_back(b - int(b/a)*a);
				break;

			default:
				break;
			}

		}
		RPNS.pop_back();
	}

	return value.back();
}

int main() {
	string str;
	cin >> str;

	deque<RPNnode> rpn;
	RPNprocedure(rpn, str);
	cout << calculate(rpn) << endl;

	return 0;
}

