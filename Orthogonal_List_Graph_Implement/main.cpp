/*
 * main.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: ouyan
 */

#include "OrthogonalList.hpp"
using namespace std;

void TestOrthogonalList() {
	OrthogonalList ol;
	ol.addVertex("a");
	ol.addVertex("b");
	ol.addVertex("c");
	ol.addVertex("d");
	ol.addVertex("e");

	ol.addEdge("a", "b");
	//ol.addEdge("b", "c");
	//ol.addEdge("c", "d");
	//ol.addEdge("d", "a");
	//ol.addEdge("c", "b");
	//ol.addEdge("c", "a");
	//ol.addEdge("b", "a");
	ol.addEdge("a", "c");
	ol.addEdge("b", "d");
	//ol.addEdge("b", "b");
	//ol.addEdge("c", "c");
	//ol.addEdge("c", "b");

	//ol.addEdge("a", "d");
	ol.addEdge("a", "e");
	//ol.addEdge("d", "b");
	//ol.addEdge("d", "c");
	//ol.addEdge("e", "b");

	ol.showVertex();
	cout << endl;
	ol.showEdge();
	cout << endl;
	ol.showEdge_In();
	cout << endl;

	ol.DepthFirstTraverse_Top(0);
}

int main() {
	TestOrthogonalList();
	cout << "Test successful! " << endl;

	return 0;
}

