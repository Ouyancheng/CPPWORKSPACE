#include <iostream>
using std::cout;
using std::endl;

float invSqrt(float x) {
	int i = *(int *)&x;
	i = 1597463007 - (i >> 1);
	x = *(float *)&i;
	return x;
}

int main() {
	float a = 100.0;
	cout << invSqrt(a) << endl;
	return 0;
}
	
