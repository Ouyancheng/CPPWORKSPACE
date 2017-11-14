/*
 * main.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <sstream>

void test() {
	AdjacentList al;
	for (unsigned int i = 0; i <= 8; i++) {
		string temp = "V";
		temp += (char) (i) + '0';
		al.addVertex(temp);
	}
	al.addEdge("V0", "V1", 1);
	al.addEdge("V0", "V2", 5);

	al.addEdge("V1", "V2", 3);

	al.addEdge("V1", "V3", 7);
	al.addEdge("V1", "V4", 5);
	al.addEdge("V2", "V4", 1);
	al.addEdge("V2", "V5", 7);

	al.addEdge("V3", "V4", 2);
	al.addEdge("V4", "V5", 3);

	al.addEdge("V3", "V6", 3);
	al.addEdge("V4", "V6", 6);
	al.addEdge("V4", "V7", 9);
	al.addEdge("V5", "V7", 5);

	al.addEdge("V6", "V7", 2);

	al.addEdge("V6", "V8", 7);
	al.addEdge("V7", "V8", 4);

	cout << al << endl;

	al.DijkstraAlgorithm(0);

	cout << "Test successful! " << endl;
}

int main() {
	test();
}


