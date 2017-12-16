//
//  UnusedCode.h
//  RBTree_Xcode
//
//  Created by 区彦成 on 2017-12-15.
//  Copyright © 2017 区彦成. All rights reserved.
//

#ifndef UnusedCode_h
#define UnusedCode_h

/*
 
 // TODO
 void rebalance_for_remove(node *parent, bool p_on_left) {
 *
 * Note that if we jump into this function, color of the node to be deleted must be black.
 * Otherwise we are done... The case has been discussed in the remove method.
 *
 node *n = (p_on_left) ? (parent->left) : (parent->right);
 if (node::get_color(n) == red) {
 node::set_color(n, black);
 return;
 }
 *
 * We know that we are to delete a black node.
 * The pointer n is the new node to replace position of p.
 * If n is red, n shouldn't be null and we can just flip n's color to satisfy the condition.
 *
 * After these two situations, the assumption of the remaining conditions will be:
 * n is black (or null);
 * The node to be deleted, p, is black.
 *
 *
 * Note that if p is black and n is black (or null),
 * the sibling of p shouldn't be null for the property of red-black-tree.
 * Otherwise, the black nodes are not equal.
 *
 node *sibling = (p_on_left) ? (parent->right) : (parent->left);
 if (parent->color == red &&
 sibling->color == black &&
 node::get_color(sibling->left) == black &&
 node::get_color(sibling->right) == black) {
 parent->color = black;
 sibling->color = red;
 // break the loop
 }
 *
 *
 if (p_on_left && sibling->color == black && node::get_color(sibling->right) == red) {
 
 } else if (!p_on_left && sibling->color == black && node::get_color(sibling->left) == red) {
 
 }
 
 }
 
 */

/*if (!p) return false;
 if (!(p->left) || !(p->right)) {
 node *pchild = (p->left) ? (p->left) : (p->right);
 if (p == root) {
 root = pchild;
 if (root) root->parent = nullptr;
 node::set_color(root, black);
 delete p;
 --node_count;
 return true;
 }
 // Pointer p is not root after that.
 bool p_on_left = (p == p->parent->left);
 if (p_on_left) {
 p->parent->left = pchild;
 if (pchild) pchild->parent = p->parent;
 } else {
 p->parent->right = pchild;
 if (pchild) pchild->parent = p->parent;
 }
 if (p->color == black) {
 rebalance_for_remove(pchild, p_on_left);
 }
 delete p;
 --node_count;
 } else {
 node *q = (p->right);
 while (q->left) q = q->left;
 data_t temp = p->data;
 p->data = q->data;
 q->data = temp;
 remove_ptr(q);
 }*/

/*if (!(p->left) && !(p->right)) {
 node *&c = (p == p->parent->left) ? (p->parent->left) : (p->parent->right);
 if (p->color == black) {
 rebalance_for_remove(c);
 }
 // remove p
 delete p;
 c = nullptr;
 --node_count;
 } else if (!(p->left) && (p->right)) {
 node *&c = (p == p->parent->left) ? (p->parent->left) : (p->parent->right);
 c = p->right;
 p->right->parent = p->parent;
 if (p->color == black)
 rebalance_for_remove(c);
 // remove p
 delete p;
 c = nullptr;
 --node_count;
 
 } else if ((p->left) && !(p->right)) {
 node *&c = (p == p->parent->left) ? (p->parent->left) : (p->parent->right);
 c = p->left;
 p->left->parent = p->parent;
 if (p->color == black)
 rebalance_for_remove(c);
 // remove p
 delete p;
 c = nullptr;
 --node_count;
 
 }*/

/*
 struct pair {
 typedef long key_t;
 typedef long value_t;
 key_t key;
 value_t value;
 bool operator < (const pair &another) const { return (key < another.key); }
 bool operator != (const pair &another) const { return (key < another.key || another.key < key); }
 bool operator == (const pair &another) const { return !(key < another.key) && !(another.key < key); }
 pair(const key_t &key = key_t(), const value_t &value = value_t()) : key(key), value(value) {}
 };
 
 struct slist_node {
 node *p;
 slist_node *next;
 };
 
 //            if (!p) return *this;
 //            if (p->left) {
 //                p = p->left;
 //                while (p->right)
 //                    p = p->right;
 //            } else {
 //                node *parent = p->parent;
 //                while (parent != nullptr && p == parent->left) {
 //                    p = parent;
 //                    parent = p->parent;
 //                }
 //                p = parent;
 //            }
 
 //            if (!p) return *this;
 //            if (p->left) {
 //                p = p->left;
 //                while (p->right)
 //                    p = p->right;
 //            } else {
 //                node *parent = p->parent;
 //                while (parent != nullptr && p == parent->left) {
 //                    p = parent;
 //                    parent = p->parent;
 //                }
 //                p = parent;
 //            }
 
 //            if (!p) return temp;
 //            if (p->right) {
 //                p = p->right;
 //                while (p->left != nullptr)
 //                    p = p->left;
 //            } else {
 //                node *parent = p->parent;
 //                while (parent != nullptr && p == parent->right) {
 //                    p = parent;
 //                    parent = p->parent;
 //                }
 //                p = parent;
 //            }
 
 //            if (!p) return *this;
 //            if (p->right) {
 //                p = p->right;
 //                while (p->left != nullptr)
 //                    p = p->left;
 //            } else {
 //                node *parent = p->parent;
 //                while (parent != nullptr && p == parent->right) {
 //                    p = parent;
 //                    parent = p->parent;
 //                }
 //                p = parent;
 //            }
 
 */


#endif /* UnusedCode_h */
