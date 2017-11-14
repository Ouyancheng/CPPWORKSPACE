/*
 * main.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: ouyan
 */

#include "RPN_Procedure.h"
#include "RPN_Calc.h"
#include <iostream>
#include <string>
using namespace std;



int main() {
	string a;
	Stack<element> result;
	while (1) {
		cin >> a;

		if (a=="exit") {
			cout << "Program exit! " << endl;
			break;
		}

		result=RPN(a);
		Stack<element> record=result;
		while (!record.empty()) {
			element e;
			e=record.pop();
			if (e.ischar==true) {
				cout << e.c << " ";
			} else {
				cout << e.i << " ";
			}
		}
		cout << endl;
		cout << RPN_Calc(result) << endl;
	}

	return 0;
}


