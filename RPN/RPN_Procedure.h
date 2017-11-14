/*
 * RPN_Procedure.h
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#ifndef RPN_PROCEDURE_H_
#define RPN_PROCEDURE_H_

#include "Stack.h"
#include <string>
using namespace std;

Stack RPN(string a) {
	Stack operation;
	Stack number;

	operation.push('#');

	int length;
	length=a.size();

	for (int i=0;i<length;i++) {
		if (a[i]=='(') {
			operation.push('(');
		} else if ((a[i]<='9')&&(a[i]>='0')) {
			number.push(a[i]);
		} else if (a[i]==')') {
			char temp=')';
			while (1) {
				temp=operation.pop();
				if (temp=='(') {
					break;
				} else {
					number.push(temp);
				}
			}
		} else if ((a[i]=='+')||(a[i]=='-')||(a[i]=='*')||(a[i]=='/')) {
			if (operation.peek()=='(') {
				operation.push(a[i]);
			} else if ((a[i]=='*')||(a[i]=='/')) {
				operation.push(a[i]);
			} else {
				while ((operation.peek()!='(')&&(operation.peek()!='#')) {
					number.push(operation.pop());
				}
				operation.push(a[i]);
			}
		}
	}

	while (operation.getTop()!=0) {
		number.push(operation.pop());
	}

	return number;

}



#endif /* RPN_PROCEDURE_H_ */
