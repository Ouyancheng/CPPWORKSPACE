/*
 * main.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: ouyan
 */

#include "AdjacentList.h"
#include <iostream>
using namespace std;
void test() {
	AdjacentList al;
	string temp = "";
	for (int i = 1; i <= 15; i++) {
		if (i < 10) {
			temp += (char) (i) + '0';
		} else {
			switch (i) {
			case 10:
				temp += "10";
				break;
			case 11:
				temp += "11";
				break;
			case 12:
				temp += "12";
				break;
			case 13:
				temp += "13";
				break;
			case 14:
				temp += "14";
				break;
			case 15:
				temp += "15";
				break;
			}
		}
		al.addVertex(temp);
		temp = "";
	}
	//Vertex 1:
	al.addEdge("1", "4");
	al.addEdge("1", "2");
	al.addEdge("1", "3");
	//Vertex 2: None
	//Vertex 3:
	al.addEdge("3", "10");
	al.addEdge("3", "7");
	al.addEdge("3", "6");
	al.addEdge("3", "9");
	//Vertex 4:
	al.addEdge("4", "8");
	al.addEdge("4", "7");
	al.addEdge("4", "10");
	//Vertex 5: None
	//Vertex 6: None
	//Vertex 7: None
	//Vertex 8: None
	//Vertex 9: None
	//Vertex 10:
	al.addEdge("10", "11");
	al.addEdge("10", "7");
	//Vertex 11:
	al.addEdge("11", "12");
	//Vertex 12: None
	//Vertex 13:
	al.addEdge("13", "4");
	al.addEdge("13", "14");
	//Vertex 14:
	al.addEdge("14", "2");
	al.addEdge("14", "3");
	al.addEdge("14", "15");
	//Vertex 15:
	al.addEdge("15", "5");

	//al.addEdge("5", "14");

	al.showVertices();
	al.showEdges();

	al.TopologicalSort();
}

int main() {
	test();
	cout << "Memory freed successful! " << endl;
	cout << INT_MAX << endl;
	cout << UINT_MAX << endl;
	cout << 0xffffffff << endl;
	return 0;
}


