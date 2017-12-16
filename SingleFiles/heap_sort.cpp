#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void int_swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp; 
}

void single_heapify(std::vector<int> &a) {
	int length = a.size(); 
	int left; 
	int right;
	int maxpos; 
	for (int i = (length - 1) / 2; i >= 0; i--) {
		left = (i) * 2 + 1;
		right = left + 1;
		maxpos = left; 
		if (right < a.size() && a[left] < a[right]) {
			maxpos = right;
		} 
		if (a[maxpos] > a[i]) {
			swap(a[maxpos], a[i]);
		}
	}
}

void heap_fix_down(std::vector<int> &a, size_t size) {
	int i = 0;
	int left;
	int right;
	int maxpos;
	while (i < size / 2) {
		// cout << i << ": " << a[i] << endl;
		left = i * 2 + 1;
		right = left + 1;
		maxpos = left;
		if (right < size && a[right] > a[left]) {
			maxpos = right;
		}
		if (a[i] < a[maxpos]) {
			// cout << "swap: " << a[i] << ", " << a[maxpos] << endl;
			swap(a[maxpos], a[i]);
			i = maxpos; 
		} else {
			break;
		}
		
	}
}

int main() {
	vector<int> a = {3, 11, 1, 4, 5, 6, 7, 10, 9, 8};
	for (int i = 0; i < (a.size() - 1) / 2; i++) {
		single_heapify(a);
	}
	for (int i = a.size() - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heap_fix_down(a, i);
	}
	
	
	for (auto i : a) {
		printf("%d ", i);
	}
	putchar('\n');
	return 0;
}