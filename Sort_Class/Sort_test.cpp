/*
 * Sort_test.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: ouyan
 */

#include "Sort.hpp"

#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <functional>
#include <map>
#include <initializer_list>
#include <list>
using namespace std;
bool Compare(int a, int b) {
	if (a < b) {
		return false;
	} else {
		return true;
	}
}
class CompareFunctor {
public:
	bool operator () (int a, int b) {
		return !(a < b);
	}
};

int main() {
	int a[10]={3,2,4,1,5,6,8,9,0,7};
	Sort::BubbleSort(a, 10, CompareFunctor());
	for (int i=0;i<10;i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');

	int b[10]={3,2,4,1,5,6,8,9,0,7};
	Sort::SelectionSort(b, 10, [=](auto &a, auto &b) mutable ->auto{return a<b;});
	for (int i=0;i<10;i++) {
		printf("%d ", b[i]);
	}
	putchar('\n');

	int c[10]={3,2,4,1,5,6,8,9,0,7};
	Sort::InsertionSort(c, 10);
	for (int i=0;i<10;i++) {
		printf("%d ", c[i]);
	}
	putchar('\n');

	int d[10]={3,2,4,1,5,6,8,9,0,7};
	Sort::ShellSort(d, 10, Compare);
	for (int i=0;i<10;i++) {
		printf("%d ", d[i]);
	}

	putchar('\n');

	puts("Merge Sort: ");
	constexpr size_t size = 10;
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 1, 2, 10};
	vector<int> v(arr, arr+size);
	deque<int> dq(arr, arr+size);

	Sort::mergeSort(arr, arr+size, CompareFunctor());
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	putchar('\n');

	Sort::mergeSort(v.begin(), v.end());
	for (auto &i : v) {
		cout << i << " ";
	}
	putchar('\n');

	Sort::mergeSort(dq.begin(), dq.end(), [](int &a, int &b){return a > b;});
	for (auto &i : dq) {
		cout << i << " ";
	}
	putchar('\n');

	puts("Heap Sort: ");
	vector<int> vec = {3,2,7,4,5,6,1,10,9,8};
	Sort::heapSort(vec.begin(), vec.end(), [](int &a, int &b){return a>b;});
	for (auto &i : vec) {
		cout << i << " ";
	}
	putchar('\n');

	int array[] = {3,2,7,4,5,6,1,10,9,8};
	Sort::heapSort(array, array+10, [](int &a, int &b){return a<b;});
	for (size_t i = 0; i<10; i++) {
		cout << array[i] << " ";
	}
	putchar('\n');

	deque<int> deq(array, array+10);
	Sort::heapSort(deq.begin(), deq.end());
	for (auto &i : deq) {
		cout << i << " ";
	}
	putchar('\n');

	puts("Quick Sort: ");
	int arrqs[] = {3,2,1,4,5,6,7,10,9,8};
	vector<int> vecqs(arrqs, arrqs+10);
	deque<int> deqqs(vecqs.begin(), vecqs.end());
	list<int> listqs(vecqs.begin(), vecqs.end());
	Sort::quickSort(arrqs, arrqs + 10, CompareFunctor());
	Sort::quickSort(vecqs.begin(), vecqs.end(), Compare);
	Sort::quickSort(deqqs.begin(), deqqs.end(), CompareFunctor());
	Sort::quickSort(listqs.begin(), listqs.end());

//	Sort::quickSort(arrqs, 0, 10, Compare);
	for (size_t i = 0; i<10; i++) {
		cout << arrqs[i] << " ";
	}
	putchar('\n');
	for (auto &i : vecqs) {
		cout << i << " ";
	}
	putchar('\n');
	for (auto &i : deqqs) {
		cout << i << " ";
	}
	putchar('\n');
	for (auto i : listqs) {
		printf("%d ", i);
	}
	putchar('\n');

	return 0;
}

//template <bool, class _Tp = void> struct enable_if {};
//template <class _Tp> struct enable_if<true, _Tp> {typedef _Tp type;};
//template <bool _Bp, class _Tp = void>
//using enable_if_t = typename std::map<_Tp, int>::iterator;//enable_if<_Bp, _Tp>::type;





