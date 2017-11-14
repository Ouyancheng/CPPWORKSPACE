/*
 * main.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: ouyan
 */

#include <iostream>
#include "Queue.h"
#include "AdjacentList.h"
using namespace std;
int main() {
	string a;
	Queue q;
	q.push_back("1", 1);
	cout << q.pop_front() << endl;
	q.push_back("2", 2);
	cout << q.pop_front() << endl;

	AdjacentList al;
	al.addVertex("A");
	al.addVertex("B");
	al.addVertex("C");
	al.addVertex("D");
	al.addVertex("E");
	al.addVertex("F");

	al.addEdge("A", "A");
	al.addEdge("A", "B");
	al.addEdge("B", "A");
	al.addEdge("C", "A");
	al.addEdge("B", "C");
	al.addEdge("A", "F");
	al.addEdge("B", "E");
	al.addEdge("C", "D");

	al.showVertex();

	al.showEdge();

	al.BreadthFirstTraverse(1);
	cout << endl;

	al.DepthFirstTraverse(1);

	return 0;

}


