/*
 * RPN_Calc.h
 *
 *  Created on: Jul 19, 2016
 *      Author: ouyan
 */

#ifndef RPN_CALC_H_
#define RPN_CALC_H_
#include "RPN_Procedure.h"
#include <string>
#include <cmath>
using namespace std;



int RPN_Calc(Stack<element> s) {
	Stack<element> a;
	Stack<int> result;
	result.push(0);
	result.push(0);
	while (!s.empty()) {
		a.push(s.pop());
	}
	//cout << "Is a empty? " << a.empty() << endl;
	while (!a.empty()) {
		element temp;
		temp=a.pop();
		if (temp.ischar==false) {
			result.push(temp.i);
			//cout << "Pushed " << temp.i << endl;

		} else if (temp.c=='+') {
			int x,y;
			x=result.pop();
			y=result.pop();
			result.push(int(y+x));
		} else if (temp.c=='-') {
			int x,y;
			x=result.pop();
			y=result.pop();
			result.push(int(y-x));
		} else if (temp.c=='*') {
			int x,y;
			x=result.pop();
			y=result.pop();
			result.push(int(y*x));
		} else if (temp.c=='/') {
			int x,y;
			x=result.pop();
			y=result.pop();
			result.push(int(y/x));
		} else if (temp.c=='%') {
			int x,y;
			x=result.pop();
			y=result.pop();
			result.push(int(y%x));
		} else if (temp.c=='^') {
			int x,y;
			x=result.pop();
			y=result.pop();
			int r=1;
			for (int i=1;i<=x;i++) {
				r=r*y;
			}
			//r=pow(y,x);
			result.push(int(r));
		} else if (temp.c=='!') {
			int x;
			int r=1;
			x=result.pop();
			for (int i=x;i>=1;i--) {
				r*=i;
			}
			result.push(r);
		} else {
			continue;
		}

	}
	//cout << result.pop() << endl;
	//cout << result.getTop() << endl;
	return result.pop();
}



#endif /* RPN_CALC_H_ */
