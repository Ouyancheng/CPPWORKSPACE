/*
 * main.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: ouyan
 */

#include <iostream>
#include <fstream>
using namespace std;

ofstream ofs;


void printMatrix(int a[][8]) {
	static int count = 0;
	++count;

	cout << "Case " << count << endl;
	ofs << "Case " << count << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i][j]==1) {
				cout << 'Q' << " ";
				ofs << 'Q' << " ";
			} else {
				cout << '.' << " ";
				ofs << '.' << " ";
			}
		}
		cout << endl;
		ofs << endl;
	}
	cout << endl;
	ofs << endl;
}

bool isDangerous(int row, int column, int a[][8]) {
	//Judge the upper line
	for (int i = 0; i < row; i++) {
		if (a[i][column] == 1) {
			return true;
		}
	}

	//Judge the upper-left line
	for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
		if (a[i][j] == 1) {
			return true;
		}
	}

	//Judge the upper-right line
	for (int i = row - 1, j = column + 1; i >= 0 && j < 8; i--, j++) {
		if (a[i][j] == 1) {
			return true;
		}
	}

	/*for (int i = row + 1, j = column - 1; i < 8 && j >= 0; i++, j--) {
		if (a[i][j] == 1) {
			return true;
		}
	}

	for (int i = row + 1, j = column + 1; i < 8 && j < 8; i++, j++) {
		if (a[i][j] == 1) {
			return true;
		}
	}*/

	return false;
}

void placeQueen(int n, int a[][8], int row) {
	if (n > 8) {
		printMatrix(a);
	} else {
		for (int i = 0; i < 8; i++) {
			a[row][i] = 1;
			if (!isDangerous(row, i, a)) {
				placeQueen(n + 1, a, row + 1);
			}
			a[row][i] = 0;
		}
	}
}

int main() {
	int a[8][8];

	ofs.open("EightQueens.txt");//, ios::app);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = 0;
		}
	}

	placeQueen(1, a, 0);
	ofs.close();
	return 0;
}

