/*
 * AdjacentMatrix.cpp
 *
 *  Created on: Aug 19, 2016
 *      Author: ouyan
 */

#include "AdjacentMatrix.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
AdjacentMatrix::AdjacentMatrix() {
	// TODO Auto-generated constructor stub
}

AdjacentMatrix::~AdjacentMatrix() {
	// TODO Auto-generated destructor stub
}

void AdjacentMatrix::addVertex(const string &vertexname) {
	for (unsigned int i=0;i<name.size();i++) {
		if (name[i]==vertexname) {
			return;
		}
	}

	a.push_back(vector<unsigned int>(a.size()+1, INT_MAX));
	a[a.size()-1][a.size()-1]=0;

	for (unsigned int i=0;i<a.size()-1;i++) {
		a[i].push_back(INT_MAX);
	}

	name.push_back(vertexname);
}

void AdjacentMatrix::addEdge(const string &from, const string &to, const unsigned int &weight) {
	bool foundfrom=false;
	bool foundto=false;
	unsigned int fromindex=0;
	unsigned int toindex=0;
	for (unsigned int i=0;i<name.size();i++) {
		if (name[i]==from) {
			foundfrom=true;
			fromindex=i;
		}
		if (name[i]==to) {
			foundto=true;
			toindex=i;
		}
		if (foundfrom && foundto) {
			break;
		}
	}

	if (!foundfrom || !foundto) {
		return;
	}

	a[fromindex][toindex]=weight;

}

void AdjacentMatrix::showVertex() const {
	cout << "Vertices: " << endl;
	for (unsigned int i=0;i<name.size();i++) {
		cout << name[i] << " ";
	}
	cout << endl;
}

void AdjacentMatrix::showEdge() const {
	cout << "Edges: " << endl;
	for (unsigned int i=0;i<a.size();i++) {
		for (unsigned int j=0;j<a[i].size();j++) {
			if (a[i][j]!=0 && a[i][j]!=INT_MAX) {
				cout << "<" << name[i] << "," << name[j] << "," << a[i][j] << "> ";
			}
		}
		cout << endl;
	}
}

void AdjacentMatrix::showMatrix() const {
	for (unsigned int i=0;i<a.size();i++) {
		for (unsigned int j=0;j<a[i].size();j++) {
			if (a[i][j]==INT_MAX) {
				cout << " ¡Þ ";
			} else {
				cout << setw(2) << hex << a[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void AdjacentMatrix::DijkstraAlgorithm(const unsigned int &index) const {
	vector<bool> visited(a.size(), false);
	vector<unsigned int> low(a.size(), INT_MAX);

	unsigned int _index=index;

	low[_index]=0u;

	unsigned int visitednum=0u;

	while (visitednum<a.size()) {
		visited[_index]=true;
		++visitednum;

		for (unsigned i=0;i<a[_index].size();i++) {
			if (!visited[i] && low[i]>low[_index]+a[_index][i]) {
				low[i]=low[_index]+a[_index][i];
			}
		}

		unsigned int min=INT_MAX;
		for (unsigned int i=0;i<low.size();i++) {
			if (!visited[i] && low[i]<min) {
				min=low[i];
				_index=i;
			}
		}
 	}

	for (unsigned int i=0;i<low.size();i++) {
		cout << low[i] << " ";
	}
	cout << endl;
}

void AdjacentMatrix::FloydAlgorithm(const unsigned int &index) const {
	vector< vector<unsigned int> > temp;
	temp=a;

	for (unsigned int k=0;k<a.size();k++) {
		for (unsigned int i=0;i<a.size();i++) {
			for (unsigned int j=0;j<a.size();j++) {
				if (temp[i][j]>temp[i][k]+temp[k][j]) {
					temp[i][j]=temp[i][k]+temp[k][j];
				}
			}
		}
	}

	for (unsigned int i=0;i<temp[index].size();i++) {
		cout << temp[index][i] << " ";
	}
	cout << endl;

}
