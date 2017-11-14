/*
 * RPN_Procedure.h
 *
 *  Created on: Jul 19, 2016
 *      Author: ouyan
 */

#ifndef RPN_PROCEDURE_H_
#define RPN_PROCEDURE_H_

#include "Stack.h"
#include "Element.h"
#include <string>
using namespace std;

typedef unsigned int uint;

static element toElement(int n) {
	element e;
	e.i=n;
	e.c='\0';
	e.ischar=false;
	return e;
}

static element toElement(char ch) {
	element e;
	e.c=ch;
	e.i=0;
	e.ischar=true;
	return e;
}


int grade(char c) {
	if ((c == '+') || (c == '-')) {
		return 1;
	} else if ((c == '*') || (c == '/') || (c == '%')) {
		return 2;
	} else if ((c == '^') || (c == '!')) {
		return 3;
	} else if (c == '#') {
		return 0;
	} else {
		return -1;
	}
}

Stack<element> RPN(string a) {
	uint length = a.size();
	Stack<char> operation;
	Stack<element> RPNS;

	operation.push('#');

	for (uint i = 0; i < length; i++) {
		if (a[i] == '(') {
			operation.push('(');
		} else if (a[i] == ')') {
			while (operation.peek() != '(') {
				RPNS.push(toElement(operation.pop()));
			}
			operation.pop();        //Pop '('
		} else if (a[i]=='!') {
			RPNS.push(toElement('!'));

		} else if (grade(a[i]) >= 0) {
			if (operation.peek() == '(') {
				operation.push(a[i]);

			} else if (grade(a[i]) > grade(operation.peek())) {
				operation.push(a[i]);

			} else {
				while ((operation.peek() != '(') && (grade(a[i]) <= grade(operation.peek()))) {
					RPNS.push(toElement(operation.pop()));
				}
				operation.push(a[i]);

			}
		} else if ((a[i] >= '0') && (a[i] <= '9')) {
			int temp = 0;
			while ((a[i] >= '0') && (a[i] <= '9')) {
				temp = temp * 10 + (int) (a[i] - '0');
				i++;
			}
			i--;
			RPNS.push(toElement(temp));
		}
	}
	while (operation.getTop()>0) {
		RPNS.push(toElement(operation.pop()));
	}
	return RPNS;
}

#endif /* RPN_PROCEDURE_H_ */
