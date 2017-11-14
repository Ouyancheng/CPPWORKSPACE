#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
int strToInt(string &str) {
	static stringstream ss;
	ss << str;
	int result;
	ss >> result;
	ss.clear();
	str.clear();
	return result;
}
bool isVaildIP(string str) {
	enum {read1, read2, read3, read4, done, error} state = read1;
	string numStr;
	size_t index = 0;
	while (true) {
		if (state == read1) {
			char charRead = str[index++];
			if (isdigit(charRead)) {
				numStr += charRead;
				continue;
			} else if (charRead == '.') {
				int result = strToInt(numStr);
				if (0 <= result && result <= 255) {
					state = read2;
				} else {
					state = error;
				}
			} else {
				state = error;
			}
		} else if (state == read2) {
			char charRead = str[index++];
			if (isdigit(charRead)) {
				numStr += charRead;
				continue;
			} else if (charRead == '.') {
				int result = strToInt(numStr);
				if (0 <= result && result <= 255) {
					state = read3;
				} else {
					state = error;
				}
			} else {
				state = error;
			}
		} else if (state == read3) {
			char charRead = str[index++];
			if (isdigit(charRead)) {
				numStr += charRead;
				continue;
			} else if (charRead == '.') {
				int result = strToInt(numStr);
				if (0 <= result && result <= 255) {
					state = read4;
				} else {
					state = error;
				}
			} else {
				state = error;
			}
		} else if (state == read4) {
			char charRead = str[index++];
			if (isdigit(charRead)) {
				numStr += charRead;
				continue;
			} else if (charRead == '\0') {
				int result = strToInt(numStr);
				if (0 <= result && result <= 255) {
					state = done;
				} else {
					state = error;
				}
			} else {
				state = error;
			}
		} else if (state == done) {
			return true;
		} else if (state == error) {
			return false;
		}
	}
	return false;
}

int main() {
	string str;
	cin >> str; 
	string strWithoutSpace;
	for (char c : str) {
		if (!isspace(c)) {
			strWithoutSpace += c;
		}
	}
	cout << strWithoutSpace << endl;
	cout << isVaildIP(strWithoutSpace) << endl;
	return 0;
}