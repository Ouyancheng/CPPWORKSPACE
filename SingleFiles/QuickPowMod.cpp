#include <iostream>
using namespace std;
template <typename T>
T quickMulMod(T a, T b, T m) {
	T temp = (b) % m;
	T result = 0;
	while (a > 0) {
		if (a & 1) {
			result = (result + temp) % m;
		}
		temp = (temp * 2) % m;
		a >>= 1;
	}
	return result;
}
template <typename T>
T quickPowMod(T a, T b, T m) {
	T result = 1;
	T temp = a % m;
	while (b > 0) {
		if (b & 1) {
			// result = (result * temp) % m;
			result = quickMulMod<T>(result, temp, m);
		}
		// temp = (temp * temp) % m;
		temp = quickMulMod<T>(temp, temp, m);
		b >>= 1;
	}
	return result;
}

int main() {
	uint32_t a = 2147483647;
	uint32_t b = 2147483647;
	uint32_t m = 2147483645;
	while (cin >> a >> b >> m) {
		cout << quickPowMod(a, b, m) << endl;
	}
	
	return 0;
}