/*
 * AVLTree_test.hpp
 *
 *  Created on: Sep 10, 2016
 *      Author: ouyan
 */

#include "AVLTree.hpp"
#include <string>
void test() {
	AVLTree<int, string> avlt;
	avlt.insert(3, "str3");
	avlt.insert(2, "str2");
	avlt.insert(1, "str1");
	avlt.insert(4, "str4");
	avlt.insert(6, "str6");
	avlt.insert(5, "str5");
	avlt.insert(7, "str7");
	avlt.insert(10, "strX");
	avlt.insert(9, "str9");
	avlt.insert(8, "str8");

	avlt.remove(10);

	avlt.remove(4);

	cout << "INORDER: " << endl;
	avlt.inorder();
	cout << "PREORDER: " << endl;
	avlt.preorder();
	cout << "POSTORDER: " << endl;
	avlt.postorder();
	cout << "LAYERORDER: " << endl;
	avlt.layerorder();
	cout << endl;

}
