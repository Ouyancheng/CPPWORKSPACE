/*
 * main.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: ouyan
 */

#include <iostream>
#include <string>
#include "RPN_Procedure.h"
#include "Stack.h"
#include "IntStack.h"
using namespace std;


int main() {
	string a;
	string reverse_RPN;
	string real_RPN;
	cin>>a;
	Stack temp;
	Stack temp2;
	temp=RPN(a);
	while (temp.getTop()!=-1) {
		reverse_RPN.append(1,temp.pop());
	}

	for (int i=reverse_RPN.size()-1;i>=0;i--) {
		real_RPN.append(1,reverse_RPN[i]);
	}

	cout << real_RPN << endl;

	for (unsigned int i=0;i<reverse_RPN.size();i++) {
		temp2.push(reverse_RPN[i]);
	}

	/*int x,y;
	IntStack b;
	cout << temp2.getTop() << endl;
	while (temp2.getTop()!=-1) {
		if ((temp2.peek()>='0')&&(temp2.peek()<='9')) {
			b.push((int)temp2.pop()-'0');
			cout << "Push " << b.peek() << " "<< temp2.getTop() << endl;
		} else {
			if (temp2.pop()=='+') {

				x=b.pop();
				y=b.pop();
				cout << "Plus " << x+y << endl;
				b.push(x+y);
				cout << "Push " << b.peek() << endl;
			} else if (temp2.pop()=='-') {

				x=b.pop();
				y=b.pop();
				b.push(x-y);
			} else if (temp2.pop()=='*') {

				x=b.pop();
				y=b.pop();
				cout << "Multiply " << x*y << endl;
				b.push(x*y);
				cout << "Push " << b.peek() << endl;
			} else if (temp2.pop()=='/') {

				x=b.pop();
				y=b.pop();
				b.push(x/y);
			}
		}
	}
	cout << b.getTop() << endl;
	cout << b.peek() << endl;*/

	return 0;
}
