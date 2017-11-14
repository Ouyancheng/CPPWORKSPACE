#include <iostream>
using namespace std;

template<class T>
class lnode {
public:
	T data;
	lnode <T> *previous;
	lnode <T> *next;
	
	lnode <T>(T data, lnode<T> *previous) : data(data), previous(previous), next(nullptr) {

	}
};

template<class T>
class Linklist {
private:
	lnode<T> *head;
	lnode<T> *tail;
	unsigned int size;

public:
	Linklist() {
		head=tail=nullptr;
		size=0u;
	}

	~Linklist() {
		lnode<T> *p = head;
		lnode<T> *q = head;
		if (p!=nullptr) {
			while (p->next!=nullptr) {
				q=p->next;
				delete p;
				p=q;
			}
			delete p;
		}
	}

	bool insert(T data) {
		if (head==nullptr) {
			head=new lnode<T>(data, nullptr);
			tail=head;
			++size;
			return true;
		}
		else {
			lnode<T> *p=head;
			while (p->next!=nullptr) {
				p=p->next;
			}
			p->next=new lnode<T>(data, p);
			if (p->next==nullptr) {
				return false;
			}
			else {
				++size;
				return true;
			}
		}

	}

	bool remove(unsigned int position) {
		if (position < 0u || position>=size) {
			return false;
		}
		lnode<T> *p=head;
		for (unsigned int i=0u; i<position; i++) {
			p=p->next;
		}

		if (p==head) {
			head=head->next;
			delete p;
			--size;
		}
		else {
			lnode<T> *q = p->previous;
			q->next=p->next;
			p->next->previous=q;
			delete p;
			--size;
		}
	}

	void show() {
		cout << "Size: " << size << endl;
		lnode<T> *p = head;
		while (p!=nullptr) {
			cout << p->data << " ";
			p=p->next;
		}
	}
};

int main() {
	Linklist<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);

	a.show();

	a.remove(3);
	a.remove(0);

	a.show();

	return 0;
}