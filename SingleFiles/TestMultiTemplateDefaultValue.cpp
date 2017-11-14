#include <iostream>
#include <iomanip>
using namespace std;
int a[100][100];
template <int x, int mx> 
struct next_coord_x {
	static const int value = x - 1;
};
template <int y, int my> 
struct next_coord_y {
	static const int value = y + 1;
};
template <int my>
struct next_coord_y<my, my> {
	static const int value = 0;
};
template <int mx>
struct next_coord_x<0, mx> {
	static const int value = mx;
};
template <int x, int mx>
struct prev_coord_x {
	static const int value = x + 1;
}; 
template <int mx>
struct prev_coord_x<mx, mx> {
	static const int value = 0;
}; 
template <int y, int my>
struct prev_coord_y {
	static const int value = y - 1;
}; 
template <int my>
struct prev_coord_y<0, my> {
	static const int value = my;
}; 

template <int x, int y, int mx, int my, int i, int mi>
struct magic_matrix {
	static constexpr void print() {
		(a[x][y] == 0) ? 
		((void)(a[x][y] = i), 
			magic_matrix<next_coord_x<x, mx>::value, next_coord_y<y, my>::value, mx, my, i + 1, mi>::print()) : 
		((void)magic_matrix<prev_coord_x<prev_coord_x<x, mx>::value, mx>::value, prev_coord_y<y, my>::value, mx, my, i, mi>::print());
	}
};
template <int x, int y, int mx, int my, int mi>
struct magic_matrix<x, y, mx, my, mi, mi> {
	static void print() {

	}
};

int main() {
	const int b = 12; 
	magic_matrix<0, b / 2, b - 1, b - 1, 1, b * b + 1>::print();
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			cout << setw(6) << left << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}





// cout << test<1, 1>::value << endl;
// template <int a, int b>
// struct test {
// 	static const int value = a + b;
// }; 
// template <int a>
// struct test<a, 1> {
// 	static const int value = 1;
// };