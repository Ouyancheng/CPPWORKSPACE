//
//  RBTree.hpp
//  RBTree_Xcode
//
//  Created by 区彦成 on 2017-07-20.
//  Copyright © 2017 区彦成. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>
#include <queue>

class RBTree {
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
	typedef bool color_t;
	typedef long data_t;
	static const color_t red = false;
	static const color_t black = true;

	struct node {
		color_t color;
		node *parent;
		node *left;
		node *right;
		data_t data;
		node(node *parent, const data_t &data, color_t color = red) :
		color(color), parent(parent), left(nullptr), right(nullptr), data(data) {}
		static inline node * minimum(node *p) {
			if (!p) return nullptr;
			while (p->left != nullptr)
				p = p->left;
			return p;
		}
		static inline node * maximum(node *p) {
			if (!p) return nullptr;
			while (p->right != nullptr)
				p = p->right;
			return p;
		}
		static inline color_t get_color(node *p) { return (p) ? (p->color) : (black); }
		static inline void set_color(node *p, color_t color) { if (p) p->color = color; }
	};
	
	struct slist_node {
		node *p;
		slist_node *next;
	};

	node *root;
	size_t node_count;
	node *leftmost;
	node *rightmost;
public:
	typedef const node *const const_node_ptr_t;
	struct iterator_prototype {
		iterator_prototype(node *ptr) : p(ptr) {}
		data_t operator *() const { return p->data; }
		const data_t * operator -> () const { return &(p->data); }
		bool is_null() const { return (!p); }
		iterator_prototype operator ++ () {
			if (!p) return *this;
			if (p->right) {
				p = p->right;
				while (p->left != nullptr)
					p = p->left;
			} else {
				node *parent = p->parent;
				while (parent != nullptr && p == parent->right) {
					p = parent;
					parent = p->parent;
				}
				p = parent;
			}
			return *this;
		}
		iterator_prototype operator ++ (int) {
			iterator_prototype temp = (*this);
			if (!p) return temp;
			if (p->right) {
				p = p->right;
				while (p->left != nullptr)
					p = p->left;
			} else {
				node *parent = p->parent;
				while (parent != nullptr && p == parent->right) {
					p = parent;
					parent = p->parent;
				}
				p = parent;
			}
			return temp;
		}
		iterator_prototype operator -- () {
			if (!p) return *this;
			if (p->left) {
				p = p->left;
				while (p->right)
					p = p->right;
			} else {
				node *parent = p->parent;
				while (parent != nullptr && p == parent->left) {
					p = parent;
					parent = p->parent;
				}
				p = parent;
			}
			return *this;
		}
		iterator_prototype operator -- (int) {
			if (!p) return *this;
			iterator_prototype temp = *this;
			if (p->left) {
				p = p->left;
				while (p->right)
					p = p->right;
			} else {
				node *parent = p->parent;
				while (parent != nullptr && p == parent->left) {
					p = parent;
					parent = p->parent;
				}
				p = parent;
			}
			return temp;
		}
		static node * succ(node *p) {
			if (!p) return nullptr;
			if (p->right) {
				p = p->right;
				while (p->left)
					p = p->left;
			} else {
				node *parent = p->parent;
				while (parent && p == parent->right) {
					p = p->parent;
					parent = p->parent;
				}
				p = parent;
			}
			return p;
		}
		static node * pred(node *p) {
			if (!p) return nullptr;
			if (p->left) {
				p = p->left;
				while (p->right)
					p = p->right;
			} else {
				node *parent = p->parent;
				while (parent && p == parent->left) {
					p = p->parent;
					parent = p->parent;
				}
				p = parent;
			}
			return p;
		}
	private:
		node *p;
	};
	struct preorder_iterator_prototype {
		bool is_null() { return (p == nullptr); }
		preorder_iterator_prototype(node *p, node *root) : p(p), root(root) {}
		preorder_iterator_prototype operator ++ () {
			if (!p) return *this;
			if (p->left) {
				p = p->left;
			} else if (p->right) {
				p = p->right;
			} else {
				node *parent = p->parent;
				while (parent != nullptr && p != parent->left) {
					p = parent;
					parent = p->parent;
				}
				if (parent)
					p = parent->right;
				else
					p = root->right;
			}
			return *this;
		}
		data_t operator * () {
			return p->data;
		}
	private:
		node *p;
		node *root;
	};
private:
	void destroy_subtree(node *subroot) {
		if (subroot) {
			destroy_subtree(subroot->left);
			destroy_subtree(subroot->right);
			delete subroot;
		}
	}
	void copy_subtree(node *&dest, const node *src, node *dest_parent) const {
		if (src) {
			dest = new node(dest_parent, src->data, src->color);
			copy_subtree(dest->left, src->left, dest);
			copy_subtree(dest->right, src->right, dest);
		}
	}
	node * find_leftmost(node *subroot) const { return node::minimum(subroot); }
	node * find_rightmost(node *subroot) const { return node::maximum(subroot); }
	node * find_subtree(node *subroot, const data_t &data) const {
		while (subroot != nullptr && subroot->data != data)
			subroot = (data < subroot->data) ? (subroot->left) : (subroot->right);
		if (!subroot) { return nullptr; }
		return subroot;
	}

	void left_rotate(node *&p) {
		node *c = p;
		p = p->right;
		p->parent = c->parent;
		if (p->left) p->left->parent = c;
		c->right = p->left;
		c->parent = p;
		p->left = c;
	}
	void right_rotate(node *&p) {
		node *c = p;
		p = p->left;
		p->parent = c->parent;
		c->left = p->right;
		if (p->right) p->right->parent = c;
		p->right = c;
		c->parent = p;
	}
	/* Rotation that can auto determine the axis */
	/**
	 * It's a wise idea to determine the axis inside the rotation function,
	 * because you don't need to do that everytime you need rotation.
	 */
	void auto_left_rotate(node *p) {
		node *q = p->right;
		// Axis specific
		if (p->parent == nullptr) {
			root = q;
		} else if (p == p->parent->left) {
			p->parent->left = q;
		} else {
			p->parent->right = q;
		}
		// Common code
		q->parent = p->parent;
		p->right = q->left;
		if (q->left) q->left->parent = p;
		q->left = p;
		p->parent = q;
	}
	void auto_right_rotate(node *p) {
		node *q = p->left;
		if (p == root) {
			root = q;
		} else if (p == p->parent->left) {
			p->parent->left = q;
		} else {
			p->parent->right = q;
		}
		q->parent = p->parent;
		p->left = q->right;
		if (q->right) q->right->parent = p;
		q->right = p;
		p->parent = q;
		
	}
	bool insert_unique_priv(const data_t &data) {
		if (!root) {
			root = new node(nullptr, data, black);
			++node_count;
			leftmost = rightmost = root;
			return true;
		}
		node *p = root;
		node *parent = nullptr;
		bool comp = true;
		while (p != nullptr && p->data != data) {
			parent = p;
			comp = (data < p->data);
			p = comp ? p->left : p->right;
		}
		if (!p) {
			node *&c = comp ? parent->left : parent->right;
			c = new node(parent, data, red);
			++node_count;
			if (data < leftmost->data) leftmost = c;
			if (rightmost->data < data) rightmost = c;
			auto_rebalance_for_insert(c);
			return true;
		}
		return false;
	}
	bool insert_equal_priv(const data_t &data) {
		if (!root) {
			root = new node(nullptr, data, black);
			++node_count;
			leftmost = rightmost = root;
			return true;
		}
		node *p = root;
		node *parent = nullptr;
		bool comp = true;
		while (p != nullptr) {
			parent = p;
			comp = (data < p->data);
			p = (comp) ? p->left : p->right;
		}
		node *&c = ((comp) ? (parent->left) : (parent->right));
		c = new node(parent, data, red);
		++node_count;
		if (data < leftmost->data) leftmost = c;
		if (rightmost->data < data) rightmost = c;
		auto_rebalance_for_insert(c);
		return true;
	}
	void rebalance_for_insert(node *child) {
		while (1) {
			node *parent = child->parent;
			if (!parent) {
				node::set_color(root, black);
				break;
			}
			/*
			 * If the parent pointer is null, then the child is the root...
			 * The parent pointer should not be null after this statement.
			 */
			if (node::get_color(child->parent) == black) {
				break;
			}
			/*
			 * If the parent pointer is black, the rebalance is done.
			 */
			node *grandparent = parent->parent;
			/*
			 * Note that the grandparent pointer shouldn't be null.
			 * If it is, the color of parent pointer should be black because the root of Red-Black-Tree must be black.
			 * But the greatgrandparent pointer could be null...
			 */
			if (!grandparent) {
				node::set_color(root, black);
				break;
			}
			/* 
			 * The if statement above is dummy, because if the grandparent pointer is null,
			 * it means that the parent pointer is the root, and it's always black.
			 */
			node *greatgrandparent = (grandparent->parent);
			bool parent_on_left = (parent == grandparent->left);
			bool child_on_left = (child == parent->left);
			bool grandparent_on_left = (greatgrandparent) ? (grandparent == greatgrandparent->left) : (true);
			node *uncle = (parent_on_left) ? (grandparent->right) : (grandparent->left);
			if (node::get_color(uncle) == black) {
				if (parent_on_left && child_on_left) {
					// printf("LL\n");
					if (!greatgrandparent) {
						node::set_color(parent, black);
						node::set_color(grandparent, red);
						right_rotate(root);
					} else {
						node *&rotate_axis = grandparent_on_left ? greatgrandparent->left : greatgrandparent->right;
						node::set_color(parent, black);
						node::set_color(grandparent, red);
						right_rotate(rotate_axis);
					}
					// break the loop
				} else if (!parent_on_left && !child_on_left) {
					// printf("RR\n");
					node *&rotate_axis = greatgrandparent ?
					(grandparent_on_left ? greatgrandparent->left : greatgrandparent->right) :
					(root);
					node::set_color(parent, black);
					node::set_color(grandparent, red);
					left_rotate(rotate_axis);
					// break the loop
				} else if (parent_on_left && !child_on_left) {
					// printf("LR\n");
					node *&rotate_axis_1st = grandparent->left;
					node *&rotate_axis_2nd = greatgrandparent ?
					(grandparent_on_left ? greatgrandparent->left : greatgrandparent->right) :
					(root);
					node::set_color(child, black);
					node::set_color(grandparent, red);
					left_rotate(rotate_axis_1st);
					right_rotate(rotate_axis_2nd);
					// break the loop
				} else {
					// printf("RL\n");
					node *&rotate_axis_1st = grandparent->right;
					node *&rotate_axis_2nd = greatgrandparent ?
					(grandparent_on_left ? greatgrandparent->left : greatgrandparent->right) :
					(root);
					node::set_color(child, black);
					node::set_color(grandparent, red);
					right_rotate(rotate_axis_1st);
					left_rotate(rotate_axis_2nd);
					// break the loop
				}
				break;
			} else {
				// printf("Color flip\n");
				node::set_color(parent, black);
				node::set_color(uncle, black);
				node::set_color(grandparent, red);
				child = grandparent;
			}

		}
		
	}
	/* Same as rebalance_for_insert, but uses the auto_rotations. */
	void auto_rebalance_for_insert(node *child) {
		// puts("Auto rebalance");
		while (true) {
			if (child == root) {
				node::set_color(root, black);
				break;
			}
			node *parent = child->parent;
			if (parent->color == black) break;
			/* 
			 * The parent pointer must exist, because child is not root now.
			 */
			node *grandparent = parent->parent;
			/*if (!grandparent) {
				node::set_color(root, black);
				break;
			}*/
			/*
			 * If grandparent pointer is null, it means that the parent pointer is the root, and it's always black.
			 * It's a dummy statement because the root condition has been discussed above.
			 * If the parent is root, the color of parent must be black. 
			 */
			bool child_on_left = (child == parent->left);
			bool parent_on_left = (parent == grandparent->left);
			node *uncle = ((parent_on_left) ? (grandparent->right) : (grandparent->left));
			if (node::get_color(uncle) == red) {
				node::set_color(parent, black);
				node::set_color(uncle, black);
				node::set_color(grandparent, red);
				child = grandparent;
				continue;
			} else if (child_on_left && parent_on_left) {
				node::set_color(grandparent, red);
				node::set_color(parent, black);
				auto_right_rotate(grandparent);
				break;
			} else if (!(child_on_left || parent_on_left)) {
				node::set_color(grandparent, red);
				node::set_color(parent, black);
				auto_left_rotate(grandparent);
				break;
			} else if (!child_on_left && parent_on_left) {
				node::set_color(child, black);
				node::set_color(grandparent, red);
				auto_left_rotate(parent);
				auto_right_rotate(grandparent);
				break;
			} else {
				node::set_color(child, black);
				node::set_color(grandparent, red);
				auto_right_rotate(parent);
				auto_left_rotate(grandparent);
				break;
			}
		}
	}
	
	/* Prepare for removing a node, but not refresh leftmost and rightmost. */
	node * remove_ptr(node *p) {
		// Assume that p is not null.
		node *y = p; // Pointer y is the node to delete.
		/* Find the succssive node of p and swap them. */
		if ((p->left) && (p->right)) {
			y = p->right;
			while (y->left) y = y->left;
			// Swap the data.
			data_t temp = y->data;
			y->data = p->data;
			p->data = temp;
		}
		// y is the node to delete and y contains only one or zero child.
		// x is y's child and it may be null.
		node *x = (y->left) ? (y->left) : (y->right);
		/* If x exists, then y contains one child. */
		/* Set x's parent. */
		if (x) x->parent = y->parent;
		/* Set parent's child. */
		if (y == root) {
			root = x;
		} else {
			if (y == y->parent->left) y->parent->left = x;
			else y->parent->right = x;
		}
		/**
		 * If the color of the pointer to remove is black, we need to perform a rebalance task.
		 * Otherwise, we are done.
		 */
		if (y->color == black) {
			auto_rebalance_for_remove(x, y->parent);
		}
		// if (y == leftmost) leftmost = find_leftmost(root);
		// if (y == rightmost) rightmost = find_rightmost(root);
		return y;
		
	}
	/* Reference for this method: http://www.cnblogs.com/skywang12345/p/3245399.html */
	void auto_rebalance_for_remove(node *x, node *parent) {
		/**
		 * Now x is replacing y in its position.
		 * We assume that y has been removed, and x is now in the position of y.
		 * Note that x may be null.
		 * And x have an extra black color because y is black and we need to balance the color.
		 * Now x could be red + black or black + black.
		 * The parent pointer is the parent of x, and the parent of y previously.
		 */
		node *brother;
		/**
		 * The brother must exist!!!
		 * Since we've removed a black node and replaced it with x, 
		 * there must be a black node on the right side in order to balance the whole tree before we remove the node!!!
		 */
		/**
		 * If x is root, we are done because we can just simply set the color of x to be black.
		 * If x is red, x should be a black + red node and we just need to change the color of x to be black.
		 */
		while (x != root && node::get_color(x) == black) {
			// The color of x is black + black and x is not root.
			if (x == parent->left) {
				brother = parent->right;
				if (brother->color == red) {
					/**
					 * Case 1: x is black + black and x's brother is red.
					 * Then the parent and brother's children are black.
					 */
					brother->color = black;
					parent->color = red;
					auto_left_rotate(parent);
					brother = parent->right;
				} else if (node::get_color(brother->left) == black &&
						   node::get_color(brother->right) == black) {
					/**
					 * Case 2: x is black + black and the color of the brother is black and its two children are black.
					 */
					brother->color = red;
					x = parent;
					parent = x->parent;
				} else if (node::get_color(brother->left) == red &&
						   node::get_color(brother) == black) {
					/**
					 * Case 3: x is black + black and
					 * the color of the brother is black and its two children are left red right black.
					 */
					brother->left->color = black;
					brother->color = red;
					auto_right_rotate(brother);
					brother = parent->right;
				} else {
					/**
					 * Case 4:
					 * x is black + black,
					 * x's brother is black,
					 * x's brother's right child is red,
					 * x's brother's left child is in whichever color.
					 */
					/**
					 * Swap the color of parent and brother.
					 * After rotation, parent's right child is brother's left child.
					 */
					/**
					 * The core idea of this case is to 'expand' the double black node into two single black nodes.
					 */
					brother->color = parent->color;
					parent->color = black;
					brother->right->color = black;
					auto_left_rotate(parent);
					/* Then we are ready to set the root to be black. */
					x = root;
					break;
				}
			} else {
				/* The symmetric case. */
				brother = parent->left;
				if (brother->color == red) {
					// Case 1: x is black + black and x's brother is red.
					// Then the parent and brother's children are black.
					brother->color = black;
					parent->color = red;
					auto_right_rotate(parent);
					brother = parent->left;
				} else if (node::get_color(brother->left) == black &&
						   node::get_color(brother->right) == black) {
					// Case 2: x is black + black and the color of the brother is black and its two children are black.
					brother->color = red;
					x = parent;
					parent = x->parent;
				} else if (node::get_color(brother->right) == red &&
						   node::get_color(brother) == black) {
					/*
					 * Case 3: x is black + black and
					 * the color of the brother is black and its two children are left red right black.
					 */
					brother->right->color = black;
					brother->color = red;
					auto_left_rotate(brother);
					brother = parent->left;
				} else {
					brother->color = parent->color;
					parent->color = black;
					brother->left->color = black;
					auto_right_rotate(parent);
					/* Then we are ready to set the root to be black. */
					x = root;
					break;
				}
			}
		}
		// If x is red + black or x is root, then we can set x be black to finish the rebalance.
		node::set_color(x, black);
	}
	
	void inorder_traverse_base(const node *p, void(*f)(const void*, void*), void *data_pack) const {
		if (p) {
			inorder_traverse_base(p->left, f, data_pack);
			f(p, data_pack);
			inorder_traverse_base(p->right, f, data_pack);
		}
	}
	void preorder_traverse_base(const node *p, void(*f)(const void*, void*), void *data_pack) const {
		if (p) {
			f(p, data_pack);
			preorder_traverse_base(p->left, f, data_pack);
			preorder_traverse_base(p->right, f, data_pack);
		}
	}
	void postorder_traverse_base(const node *p, void(*f)(const void*, void*), void *data_pack) const {
		if (p) {
			postorder_traverse_base(p->left, f, data_pack);
			postorder_traverse_base(p->right, f, data_pack);
			f(p, data_pack);
		}
	}
public:
	RBTree() : root(nullptr), node_count(0), leftmost(nullptr), rightmost(nullptr) {}
	RBTree(const RBTree &another) {
		destroy_subtree(root);
		// copy_subtree(root, another.root, nullptr);
		/*
		 * Rather than copying the tree recursively, this function uses the iterative method.
		 */
		node *src = another.root;
		typedef node *link, *edge;
		// printf("%s %s\n", typeid(edge).name(), typeid(link).name());
		link *dest = &root;
		node *dest_parent = nullptr;
		if (src) {
			while (true) {
				(*dest) = new node(dest_parent, src->data, src->color);
				if (src == another.leftmost) leftmost = (*dest);
				if (src == another.rightmost) { rightmost = (*dest); break; }
				if (src->left) {
					src = src->left;
					dest_parent = (*dest);
					dest = &((*dest)->left);
				} else if (src->right) {
					src = src->right;
					dest_parent = (*dest);
					dest = &((*dest)->right);
				} else {
					node *src_parent = src->parent;
					dest_parent = (*dest)->parent;
					while (src_parent != nullptr && src == src_parent->right) {
						src = src->parent;
						src_parent = src->parent;
						dest = &((*dest)->parent);
						dest_parent = (*dest)->parent;
					}
					if (src_parent) {
						src = src_parent->right;
						dest = &(dest_parent->right);
					} else {
						src = another.root->right;
						dest = &(root->right);
						dest_parent = root;
					}
				}
			}
		} else {
			root = nullptr;
		}
		node_count = another.node_count;
		// leftmost = find_leftmost(root);
		// rightmost = find_rightmost(root);
	}
	RBTree(RBTree &&another) {
		destroy_subtree(root);
		root = another.root;
		another.root = nullptr;
		node_count = another.node_count;
		leftmost = another.leftmost;
		rightmost = another.rightmost;
	}
	~RBTree() {
		destroy_subtree(root);
		/* 
		 * Use BFS to destruct the tree, from layer to layer. 
		 * The queue could be replaced by other data structures, but the frequent malloc may damage the performance.
		 */
//		std::queue<node *> Queue;
//		if (root) Queue.push(root);
//		while (!Queue.empty()) {
//			node *temp = Queue.front();
//			Queue.pop();
//			if (temp->left) Queue.push(temp->left);
//			if (temp->right) Queue.push(temp->right);
//			printf("Deleting: %ld ", temp->data);
//			delete temp;
//		}
	}
	
	bool insert_unique(const data_t &data) { return insert_unique_priv(data); }
	bool insert_equal(const data_t &data) { return insert_equal_priv(data); }
	bool erase(const data_t &data) {
		node *p = find_subtree(root, data);
		if (!p) return false;
		if (p == leftmost) { leftmost = iterator_prototype::succ(leftmost); }
		if (p == rightmost) { rightmost = iterator_prototype::pred(rightmost); }
		p = remove_ptr(p);
		delete p;
		--node_count;
		return true;
	}
	
	iterator_prototype find(const data_t &data) { return iterator_prototype(find_subtree(root, data)); }
	
	size_t size() const { return node_count; }
	iterator_prototype begin_prototype() const { return iterator_prototype(leftmost); }
	iterator_prototype end_prototype() const { return iterator_prototype(rightmost); }
	preorder_iterator_prototype preorder_begin() const { return preorder_iterator_prototype(root, root); }
	void inorder_traverse(void(*f)(const void *node_ptr, void *data_pack), void *data_pack) const {
		inorder_traverse_base(root, f, data_pack);
	}
	void preorder_traverse(void(*f)(const void *node_ptr, void *data_pack), void *data_pack) const {
		preorder_traverse_base(root, f, data_pack);
	}
	void postorder_traverse(void(*f)(const void *node_ptr, void *data_pack), void *data_pack) const {
		postorder_traverse_base(root, f, data_pack);
	}
	void layerorder_traverse(void(*f)(const void *node_ptr, void *data_pack), void *data_pack) const {
		if (!root) return;
		std::queue<node *> Queue;
		Queue.push(root);
		while (!Queue.empty()) {
			node *temp = Queue.front();
			f(temp, data_pack);
			Queue.pop();
			if (temp->left)
				Queue.push(temp->left);
			if (temp->right)
				Queue.push(temp->right);
		}
	}
	void preorder_traverse_iterative(void(*f)(const void *node_ptr, void *data_pack), void *data_pack) const {
		if (!root) return;
		node *p = root;
		while (true) {
			f(p, data_pack);
			if (p == rightmost) break; /* To prevent deadloop */
			if (p->left) p = p->left;
			else if (p->right) p = p->right;
			else {
				node *parent = p->parent;
				while (parent != nullptr && p == parent->right) {
					p = p->parent;
					parent = p->parent;
				}
				if (parent) {
					p = parent->right;
				} else {
					p = root->right;
				}
			}
		}
	}
	
};

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



#endif /* RBTree_hpp */
