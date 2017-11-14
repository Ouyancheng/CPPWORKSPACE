#include <cstdio>
#include <typeinfo>
#include <functional>
using namespace std;
int max(int a, int b) {
	return (a < b) ? (b) : (a);
}
int min(int a, int b) {
	return (a < b) ? (a) : (b);
}
int (*function_returns_max(int a, int b))(int, int) {
	printf("%d %d\n", a, b);
	return max;
}
int (*function_returns_min(int a, int b))(int, int) {
	printf("%d %d\n", a, b);
	return min;
}
int main(int argc, char **argv) {
	int (*((*fptr)(int, int)))(int, int) = function_returns_max;
	// auto fptr2 = function_returns_min;
	std::function<int(*(int, int))(int, int)> fptr3 = function_returns_min;
	// const bool equal = (typeid(fptr) == typeid(fptr2));
	printf("%d\n", (fptr(1, 2))(6, 8));
	printf("%d\n", fptr3(1, 2)(6, 8));
	// printf("%d\n", static_cast<const int>(equal));
	return 0;
}