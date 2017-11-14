/*
 * AdjacentMatrix.h
 *
 *  Created on: Aug 19, 2016
 *      Author: ouyan
 */

#ifndef ADJACENTMATRIX_H_
#define ADJACENTMATRIX_H_
#include <vector>
#include <string>
using namespace std;



class AdjacentMatrix {
public:
	AdjacentMatrix();
	virtual ~AdjacentMatrix();

	void addVertex(const string &vertexname);

	void addEdge(const string &from, const string &to, const unsigned int &weight);

	void showVertex() const;

	void showEdge() const;

	void showMatrix() const;

	void DijkstraAlgorithm(const unsigned int &index) const;

	void FloydAlgorithm(const unsigned int &index) const;

private:
	vector< vector<unsigned int> > a;
	vector<string> name;
};

#endif /* ADJACENTMATRIX_H_ */
