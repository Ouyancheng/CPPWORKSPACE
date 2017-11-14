/*
 * main.cpp
 *
 *  Created on: Aug 19, 2016
 *      Author: ouyan
 */

#include "AdjacentMatrix.h"
#include <iostream>

int main() {
	AdjacentMatrix am;
	am.addVertex("A");
	am.addVertex("B");
	am.addVertex("C");
	am.addVertex("D");

	am.addEdge("A", "B", 2);
	am.addEdge("A", "C", 6);
	am.addEdge("A", "D", 4);

	am.addEdge("B", "C", 3);

	am.addEdge("C", "A", 7);
	am.addEdge("C", "D", 1);

	am.addEdge("D", "A", 5);
	am.addEdge("D", "C", 12);

	am.showVertex();
	am.showEdge();

	am.showMatrix();

	am.FloydAlgorithm(0);
	am.FloydAlgorithm(1);
	am.FloydAlgorithm(2);
	am.FloydAlgorithm(3);

	cout << endl;

	am.DijkstraAlgorithm(0);
	am.DijkstraAlgorithm(1);
	am.DijkstraAlgorithm(2);
	am.DijkstraAlgorithm(3);

	return 0;
}


