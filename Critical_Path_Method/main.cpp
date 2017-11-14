/*
 * main.cpp
 *
 *  Created on: Aug 22, 2016
 *      Author: ouyan
 */

#include "OrthogonalList.h"
using namespace std;
int main() {
	OrthogonalList ol;

	ol.addVertex("1");
	ol.addVertex("2");
	ol.addVertex("3");
	ol.addVertex("4");
	ol.addVertex("5");
	ol.addVertex("6");

	ol.addEdge("1", "2", 6);
	ol.addEdge("2", "3", 6);
	ol.addEdge("3", "4", 6);
	ol.addEdge("3", "5", 3);
	ol.addEdge("4", "6", 8);
	ol.addEdge("5", "6", 6);

	//ol.print();
	//ol.rprint();

	//cout << ol << endl;

	/*vector<int> etv;
	stack<unsigned int> s;
	ol.TopologicalSort_CPM(s, etv);

	for (unsigned int i=0;i<etv.size();i++) {
		cout << etv[i] << " ";
	}
	cout << endl;
	for (unsigned int i=0;i<etv.size();i++) {
		cout << s.top() << " ";
		s.pop();
	}*/

	ol.CriticalPathMethod();

	return 0;
}

