#include <iostream>
using std::cout;
using std::endl;

template <int n>
struct numberType {
	enum {value = n};
};

template <bool b>
struct boolType;

template <>
struct boolType<true> {
	enum {value = true};
};

template <>
struct boolType<false> {
	enum {value = false};
};

template <class T, class U>
struct isEqualType {
	enum {value = typename boolType<false>::value};
};

template <class T>
struct isEqualType<T, T> {
	enum {value = typename boolType<true>::value};
};




int main() {
	cout <<  isEqualType<char, char>::value << " " << isEqualType<char, int>::value << endl;
	return 0;
}