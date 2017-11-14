#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


class var {

public:

	class VHolder {
	public:
		virtual ~VHolder() {

		}

		

		virtual VHolder * copy() const = 0;
	};

	template<typename Type>
	class Holder : public VHolder {
	public:
		Type data;
	public:
		Holder(Type a) : data(a) {

		}

		auto getData() -> Type {
			return &data;
		}

		Holder * copy() const {
			return this;
		}
	};


private:
	VHolder *hptr;
public:
	var() : hptr(nullptr) {

	}
	template<typename Type>
	var(Type a) : hptr(new Holder<Type>(a)) {

	}
	virtual ~var() {
		delete hptr;
	}

	template<typename Type>
	static Type var_cast(var *v) {
		return *((static_cast<Holder<Type> *>(v->hptr))->getData());
	}

	template<typename Type>
	Type operator = (Type a) {
		delete hptr;
		hptr = new Holder<Type>(a);
		return a;
	}

	friend std::ostream & operator << (std::ostream &out, var &v);





	

};

std::ostream & operator << (std::ostream &out, var &v) {
	return out;
}


int main() {
	var a(1024);
	var b('b');
	var c(3.14);

	a=string("Hello World!~");

	cout << var::var_cast<string>(&a) << endl;
	cout << var::var_cast<char>(&b) << endl;
	cout << var::var_cast<double>(&c) << endl;

	cout << b << endl;

	return 0;
}
