/*
 * main.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"

void Test() {
	AdjacentList al;
	al.addVertex("A");
	al.addVertex("B");
	al.addVertex("C");
	al.addVertex("D");
	al.addVertex("E");
	al.addVertex("F");
	/*al.addEdge("A", "B", 10);
	al.addEdge("B", "D", 12);
	al.addEdge("C", "E", 6);
	al.addEdge("E", "F", 16);
	al.addEdge("B", "C", 18);
	al.addEdge("E", "D", 8);
	al.addEdge("E", "B", 9);*/
	al.addEdge("A", "B", 10);
	al.addEdge("B", "C", 12);
	al.addEdge("D", "C", 6);
	al.addEdge("E", "D", 8);
	al.addEdge("E", "F", 9);
	al.addEdge("F", "A", 18);
	al.addEdge("E", "A", 8);
	al.addEdge("A", "D", 16);
	al.addEdge("B", "D", 9);
	cout << al << endl;

	al.KruskalAlgorithm();
}

int main() {
	Test();
	cout << endl << "Test successful! " << endl;
	return 0;

}


