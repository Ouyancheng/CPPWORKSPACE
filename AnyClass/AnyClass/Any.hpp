#pragma once
class Any {

public:
	class VHolder {
	public:
		virtual ~VHolder() {

		}

		virtual void * getDataPointer() = 0;
		virtual VHolder * clone() = 0;
	};

	template<class T>
	class Holder :public VHolder {
	public:
		template<class T>
		Holder(const T &data) : data(data) {

		}
		

		virtual ~Holder() {

		}

		VHolder * clone() {
			return new Holder<T>(data);
		}

		void * getDataPointer() {
			return &data;
		}



	private:
		T data;
	};

public:
	Any() : p(nullptr) {

	}

	template<class T>
	Any(const T data) : p(new Holder<T>(data)) {

	}

	Any & operator = (Any &another) {
		delete p;
		if (another.getPointer() == nullptr) {
			p = nullptr;
		}
		else {
			p = another.getPointer()->clone();
		}

		return another;
	}

	explicit Any(Any &another) {
		if (another.getPointer() == nullptr) {
			p = nullptr;
		}
		else {
			p = another.getPointer()->clone();
		}
		
	}

	template<class T>
	T operator = (const T &data) {
		delete p;
		p = new Holder<T>(data);
		return data;
	}

	

	virtual ~Any() {
		delete p;
	}

	VHolder * getPointer() {
		return p;
	}

private:
	VHolder *p;
	
	template <class T>
	friend static auto Any_cast(Any &a)->T;

};

template <class T>
static auto Any_cast(Any &a) -> T {
	return a.p ? *(static_cast<T *>(a.getPointer()->getDataPointer())) : T();
}



