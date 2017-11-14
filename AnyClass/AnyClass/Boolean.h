#pragma once
#include <iostream>
#include <string>
class Boolean {
public:

	Boolean() : b(false) {

	}

	Boolean(bool b) : b(b) {

	}

	template<class T>
	Boolean(const T &a) : b(a) {

	}

	virtual ~Boolean() {

	}

	bool getValue() {
		return b;
	}
	

private:
	bool b;
	friend std::ostream & operator << (std::ostream &out, Boolean &b);
};

std::ostream & operator << (std::ostream &out, Boolean &b) {
	out << (b.b ? "true" : "false");
	return out;
}

std::istream & operator >> (std::istream &in, Boolean &b) {
	std::string temp;
	in >> temp;
	if (temp == "false" || temp == "0") {
		b = false;
	}
	else {
		b = true;
	}

	return in;

}
