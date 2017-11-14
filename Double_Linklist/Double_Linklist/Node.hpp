#pragma once

template<class T>
struct node {
	T data;
	node *previous;
	node *next;

	node(T data = (T)0, node<T> *previous = nullptr)
		: data(data), previous(previous), next(nullptr) {

	}
};