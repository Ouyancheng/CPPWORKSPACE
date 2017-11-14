/*
 * main.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#include "PriorityQueue.h"
#include <iostream>
using namespace std;
int main()
{
	PriorityQueue pq;
	pq.insert(3);
	//cout << pq.getLeftmost()->data << endl;

	pq.insert(5);
	//cout << pq.getLeftmost()->data << endl;

	pq.insert(9);
	//cout << pq.getLeftmost()->data << endl;

	pq.insert(1);
	//cout << pq.getLeftmost()->data << endl;

	pq.insert(2);
	//cout << pq.getLeftmost()->data << endl;

	pq.insert(1);

	cout << "Root: " << pq.getRoot()->data << endl;

	pq.InorderTraverse(pq.getRoot());
	cout << endl;
	pq.PreorderTraverse(pq.getRoot());
	cout << endl;
	pq.PostorderTraverse(pq.getRoot());
	cout << endl;

	/*cout << "Smallest: " << pq.pop_smallest() << endl;
	 pq.InorderTraverse(pq.getRoot());
	 cout << endl;
	 pq.PreorderTraverse(pq.getRoot());
	 cout << endl;
	 pq.PostorderTraverse(pq.getRoot());
	 cout << endl;

	 cout << "Smallest: " << pq.pop_smallest() << endl;
	 pq.InorderTraverse(pq.getRoot());
	 cout << endl;
	 pq.PreorderTraverse(pq.getRoot());
	 cout << endl;
	 pq.PostorderTraverse(pq.getRoot());
	 cout << endl;*/

	for (unsigned int i = 0; i < 6; i++)
	{
		cout << pq.pop_smallest() << " ";
	}
	cout << pq.pop_smallest() << endl;

	return 0;
}

