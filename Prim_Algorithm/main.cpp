/*
 * main.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	AdjacentList al;
	al.addVertex("A");
	al.addVertex("B");
	al.addVertex("C");
	al.addVertex("D");
	al.addVertex("E");
	al.addVertex("F");

	al.addEdge("A", "B", 10);
	al.addEdge("B", "C", 12);
	al.addEdge("C", "D", 6);
	al.addEdge("D", "E", 8);
	al.addEdge("E", "F", 9);
	al.addEdge("A", "F", 18);
	al.addEdge("A", "D", 16);
	al.addEdge("A", "E", 8);
	al.addEdge("B", "D", 9);

	al.showVertex();
	al.showEdge();
	al.PrimAlgorithm(0);

	return 0;
}


