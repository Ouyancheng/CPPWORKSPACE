/*
 * main.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: ouyan
 */

#include "AVLTree.hpp"
#include <cstdlib>


void test() {
	AVLTree<int> avl;

	avl.insert(3);
	avl.insert(2);
	avl.insert(1);
	avl.insert(4);
	avl.insert(5);
	avl.insert(6);
	avl.insert(7);
	avl.insert(10);
	avl.insert(9);
	avl.insert(8);


	avl.insert(26);
	avl.insert(16);
	avl.insert(18);
	avl.insert(17);
	avl.insert(36);
	avl.insert(30);
	avl.insert(28);
	avl.insert(27);
	avl.insert(31);
	avl.insert(38);
	avl.insert(37);



	avl.show();


	avl.remove(26);
	avl.show();
}



int main() {
	test();

	system("pause");
	return 0;
}


