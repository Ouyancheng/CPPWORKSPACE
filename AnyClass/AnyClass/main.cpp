// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Any.hpp"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <vector>
#include "Boolean.h"
void TestAny();
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Any a1(10);
	Any a2(20.6);
	Any a3('a');
	Any a4(a3);
	Any a5;
	Any a6;

	a1 = 3.14;
	a1 = a2;

	a5 = std::string("Hello World!~");

	a6 = a5;

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << Any_cast<double>(a1) << " "
		<< Any_cast<double>(a2) << " "
		<< Any_cast<char>(a3) << " " 
		<< Any_cast<char>(a4) << std::endl;

	std::cout << Any_cast<std::string>(a5) << "\n" << Any_cast<std::string>(a6) << std::endl;

	TestAny();

	std::system("pause");
    return 0;
}

void TestAny() {
	Any *a7 = new Any();
	(*a7) = 'A';
	Any a8(*a7);

	delete a7;

	std::cout << Any_cast<char>(a8) << std::endl;

	std::vector<Any> v;
	v.push_back(Any(1));
	v.push_back(Any('A'));
	v.push_back(Any(std::string("A+")));
	v.push_back(Any(true));

	std::cout << Any_cast<int>(v[0]) << '\n'
		<< Any_cast<char>(v[1]) << '\n'
		<< Any_cast<std::string>(v[2]) << '\n'
		<< Any_cast<Boolean>(v[3]) << std::endl;
}


