#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <windows.h>
#include <cstdlib>
using std::cout;
using std::endl;
using std::putchar;
using std::printf;
using std::system;
using std::string;
using std::stringstream;
using std::cin;
using std::getline;
int main() {
	system("color 1E");
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	string a;
	//cin >> a;
	getline(cin, a);

	string b;
	char pstr[1000]; 

	sprintf(pstr, a.c_str());

	stringstream ss;

	ss << a;
	string c;
	ss >> c;

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	cout << c << endl;

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	cout << pstr << endl;

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf(a.c_str());
	putchar('\n');

	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	return 0;
}
