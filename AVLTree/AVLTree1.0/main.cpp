/*
 * main.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: ouyan
 */

#include "AVLTree.hpp"

int main() {
	AVLTree<int, int> bst;
	bst.insert(3, 3);
	bst.insert(2, 2);
	bst.insert(1, 1);
	bst.insert(4, 4);
	bst.insert(5, 5);
	bst.insert(6, 6);
	bst.insert(7, 7);
	bst.insert(10, 10);
	bst.insert(9, 9);
	bst.insert(8, 8);

	bst.remove(4);
	//bst.remove(5);

	/*bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);
	bst.insert(6, 6);*/

	cout << bst[6] << endl;
	cout << bst[8] << endl;
	cout << bst[9] << endl;


	bst.show();

	return 0;

}
