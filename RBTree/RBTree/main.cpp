//
//  main.cpp
//  RBTree_Xcode
//
//  Created by 区彦成 on 2017-07-20.
//  Copyright © 2017 区彦成. All rights reserved.
//

#include <iostream>
#include "RBTree.hpp"
#include <emmintrin.h>
#include <errno.h>
#include <curses.h>
#include <functional>
void print_rbtree_node(const void *node_ptr, void *data_pack) {
	printf("%ld ", ((RBTree::const_node_ptr_t)(node_ptr))->data);
}
int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	RBTree rbt;
	const size_t array_size = 9;
	long array[array_size] = {/*3,2,1,4,5,6,7,10,9,8*/ 10, 40, 30, 60, 90, 70, 20, 50, 80};
	for (size_t i = 0; i < array_size; i++) {
		rbt.insert_equal(array[i]);
	}
	rbt.inorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	rbt.preorder_traverse_iterative(print_rbtree_node, nullptr);
	putchar('\n');
	rbt.postorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	rbt.layerorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	printf("%ld\n", *(rbt.find(10)));
	
	/*for (auto i : array) {
		rbt.erase(i);
	}*/
	
	RBTree *rbt2 = new RBTree(rbt);
	rbt2->inorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	rbt2->preorder_traverse_iterative(print_rbtree_node, nullptr);
	putchar('\n');
	rbt2->postorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	rbt2->layerorder_traverse(print_rbtree_node, nullptr);
	putchar('\n');
	
	
	/*
	 10 20 30 40 50 60 70 80 90
	 30 10 20 60 40 50 80 70 90
	 20 10 50 40 70 90 80 60 30
	 30 10 60 20 40 80 50 70 90
	 */
	
	RBTree::iterator_prototype iter = rbt.begin_prototype();
	while (!iter.is_null()) {
		printf("%ld ", *iter);
		++iter;
	}
	putchar('\n');
	RBTree::iterator_prototype riter = rbt.end_prototype();
	while (!riter.is_null()) {
		printf("%ld ", *riter);
		--riter;
	}
	putchar('\n');
    
    puts("Testing postorder iterator: ");
    puts("Original: ");
    rbt.postorder_traverse(print_rbtree_node, nullptr);
    putchar('\n');
    puts("Iterator: ");
    RBTree::postorder_iterator_prototype postiter = rbt.postorder_begin();
    while (!postiter.is_null()) {
        printf("%ld ", *postiter);
        ++postiter;
    }
    putchar('\n');
    
    puts("Testing postorder iterator 2: ");
    puts("Iterator: ");
    RBTree::postorder_iterator_prototype postiter2 = rbt2->postorder_end();
    while (!postiter2.is_null()) {
        printf("%ld ", *postiter2);
        postiter2--;
    }
    putchar('\n');
    
	
//    RBTree::preorder_iterator_prototype piter = rbt.preorder_begin();
//    while (!piter.is_null()) {
//        printf("%ld ", *piter);
//        ++piter;
//    }
//    putchar('\n');
	long version = __cplusplus;
	printf("version: %ld\n", version);
	delete rbt2;
	
	return 0;
}
