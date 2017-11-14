#include <iostream>
#include <string>
#include <boost/any.hpp>
using boost::any;
using boost::any_cast;
int main() {
	int a = 0;
	double b = 1.689;
	char c = '#';

	boost::any v1(a);
	boost::any v2(a);
	boost::any v3(a);

	std::cout << typeid(a).name() << " " << typeid(b).name() << " " << typeid(c).name() << std::endl;

	auto d = static_cast< decltype(b) >(a);

	std::cout << a << " " << d << std::endl;
	std::cout << any_cast<int>(a) << " " << any_cast<double>(b) << " " << any_cast<char>(c) << std::endl;
	return 0;
}