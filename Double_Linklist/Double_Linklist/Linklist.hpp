#pragma once
#include "Node.hpp"
#include <iostream>
using namespace std;

template<class T>
class Linklist {
private:
	node<T> *head;
	node<T> *tail;
	unsigned int lsize;

public:

	Linklist() {
		head = new node<T>();
		tail = head;
		lsize = 0u;
	}

	~Linklist() {
		node<T> *p = head;
		node<T> *q = nullptr;
		while (p->next != nullptr) {
			q = p->next;
			delete p;
			p = q;
		}
		delete p;
	}

	void push_back(T data) {
		tail->next = new node<T>(data, tail);
		tail = tail->next;
		++lsize;
	}

	T pop_back() {
		if (lsize == 0u) {
			return (T)0;
		}
		T result = tail->data;
		node<T> *temp = tail;
		tail = tail->previous;
		tail->next = nullptr;
		--lsize;
		delete temp;
		if (lsize == 0u) {
			tail = head;
		}
		return result;
	}

	T back() {
		return tail->data;
	}

	T front() {
		return head->next->data;
	}

	void push_front(T data) {
		node<T> *p = new node<T>(data, head);
		p->next = head->next;
		p->next->previous = p;
		head->next = p;
		++lsize;
	}

	T pop_front() {
		if (lsize == 0u) {
			return (T)0;
		}

		node<T> *temp = head->next;

		T result = head->next->data;
		head->next = head->next->next;
		head->next->previous = head;
		

		--lsize;
		delete temp;
		if (lsize == 0u) {
			tail = head;
		}
		return result;
	}

	void insert(T data, unsigned int position) {
		if (position < 0 || position > lsize) {
			return;
		}

		if (position == lsize) {
			push_back(data);
			return;
		}
		if (position == 0) {
			push_front(data);
			return;
		}

		node<T> *p = head;
		for (unsigned int i = 0; i < position; i++) {
			p = p->next;
		}
		node<T> *q = new node<T>(data, p);
		q->next = p->next;
		p->next->previous = q;
		p->next = q;
		++lsize;
	}

	bool remove(T data) {
		
		if (lsize == 0u) {
			return false;
		}

		node<T> *p = head->next;
		node<T> *q = head;
		while (p != nullptr) {
			if (p->data == data) {
				break;
			}
			q = p;
			p = p->next;
		}

		if (p == nullptr) {
			return false;
		}

		if (p->next != nullptr) {
			q->next = p->next;
			q->next->previous = q;
		}
		else {
			q->next = p->next;
		}
		

		delete p;
		--lsize;
		if (lsize == 0u) {
			tail = head;
		}
		return true;

	}

	T & operator [](unsigned int index) {
		if (index < 0 || index >= lsize) {
			return head->data;
		}
		else {
			node<T> *p = head;
			for (unsigned int i = 0; i <= index; i++) {
				p = p->next;
			}
			return p->data;
		}
	}

	void reverse() {
		if (lsize == 0u) {
			return;
		}
		else {
			node<T> *p = head->next;
			node<T> *q = tail;
			for (unsigned int i = 0u; i < lsize / 2u; i++) {
				swap(p->data, q->data);
				p = p->next;
				q = q->previous;
			}
		}
	}

	T & middle() {
		if (lsize == 0u) {
			return head->data;
		}

		node<T> *p = head->next;
		node<T> *q = head->next;
		while (p->next != nullptr) {
			if (p->next->next == nullptr) {
				p = p->next;
			}
			else {
				p = p->next->next;
				q = q->next;
			}
		}
		return q->data;
	}

	void show() {
		node<T> *p = head;
		while (p->next != nullptr) {
			p = p->next;
			cout << p->data << " ";
		}
		cout << endl;
		//cout << p->data << endl;
	}

	void rshow() {
		if (lsize == 0u) {
			return;
		}
		node<T> *p = tail;
		while (p->previous != head) {
			cout << p->data << " ";
			p = p->previous;
		}
		cout << p->data << endl;

	}

	unsigned int size() {
		return lsize;
	}

	void swap(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
	}


};

