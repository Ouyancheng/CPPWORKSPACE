#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
using std::cout;
using std::endl;
using std::system;
using std::printf;
int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("This is a printf test! \n");
	cout << "This is a cout test! " << endl;
	
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("This is a printf test! \n");
	cout << "This is a cout test! " << endl;
	
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("This is a printf test! \n");
	cout << "This is a cout test! " << endl;
	
	system("pause");
	
	SetConsoleTextAttribute(h, wOldColorAttrs);
	printf("This is the previous color! -From printf \n");
	cout << "This is the previous color! -From cout " << endl;
	
	system("pause");
	
	return 0;
} 
