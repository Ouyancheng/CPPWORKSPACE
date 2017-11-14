#include <iostream>
using namespace std;

template<typename T>
class llnode
{
public:
	llnode(T data) : data(data), next(nullptr) {

	}
	llnode() {
		next=nullptr;
	}
	~llnode() {

	}
	
	T data;
	llnode *next;
};

template<typename T>
class Linklist
{
public:
	Linklist() {
		head=new llnode<T>;
		tail=head;
		size=0u;
	}
	~Linklist() {
		cout << "Linklist destructed! " << endl;
		llnode<T> *p=head;
		llnode<T> *q=nullptr;
		while (p->next!=nullptr) {
			q=p->next;
			delete p;
			p=q;
		}
		delete p;
	}

	void push_back(T data) {
		tail->next=new llnode<T>(data);
		tail=tail->next;
		++size;
	}

	T pop_back() {
		if (size==0u) {
			return head->data;
		}
		if (size==1u) {
			llnode<T> *p=head->next;
			T result=p->data;
			tail=head;
			head->next=nullptr;
			delete p;
			--size;
			return result;
		}

		llnode<T> *p=head;
		while (p->next!=tail) {
			p=p->next;
		}
		tail=p;
		llnode<T> *q=p->next;
		T result=q->data;
		p->next=nullptr;
		delete q;
		--size;
		return result;
	}

	void push_front(T data) {
		if (size==0u) {
			head->next=new llnode<T>(data);
			++size;
			tail=head->next;
			return;
		} else {
			llnode<T> *p=new llnode<T>(data);
			p->next=head->next;
			head->next=p;
			++size;
		}
	}

	T pop_front() {
		if (size==0u) {
			return head->data;
		}
		llnode<T> *p=head->next;
		head->next=p->next;
		T result=p->data;
		delete p;
		--size;
		if (size==0u) {
			head->next=nullptr;
			tail=head;
		}
		return result;
	}

	T front() {
		if (size!=0u) {
			return head->next->data;
		} else {
			return head->data;
		}
		
	}

	T back() {
		return tail->data;
	}

	T * begin() {
		return head->next;
	}

	T * end() {
		return tail;
	}

	size_t getSize() {
		return size;
	}

	T & operator [](size_t index) {
		if (index<0 || index>=size) {
			return head->data;
		}

		llnode<T> *p=head->next;
		for (size_t i=0;i<index;i++) {
			p=p->next;
		}

		return p->data;

	}

	void show() {
		cout << "Size: " << size << endl;
		//cout << (head->next) << endl;
		llnode<T> *p=head->next;
		while (p!=nullptr) {
			//cout << "Executed once! " << endl;
			cout << p->data << " ";
			p=p->next;
		}
		cout << endl;
	}

private:
	llnode<T> *head;
	llnode<T> *tail;
	size_t size;
};

int main() {
	Linklist<int> ll;
	ll.push_front(1);
	ll.push_front(2);
	ll.push_back(6);
	ll.push_back(8);
	ll.push_front(9);

	ll.push_front(1);
	ll.push_front(2);
	ll.push_back(6);
	ll.push_back(8);
	ll.push_front(9);

	ll.show();

	cout << ll.pop_front() << endl;
	cout << ll.pop_front() << endl;
	cout << ll.pop_front() << endl;
	cout << ll.pop_front() << endl;
	cout << ll.pop_front() << endl;

	cout << ll.pop_back() << endl;
	cout << ll.pop_back() << endl;
	cout << ll.pop_back() << endl;
	cout << ll.pop_back() << endl;
	cout << ll.pop_back() << endl;

	ll.pop_front();
	ll.push_front(1);
	ll.pop_back();
	ll.push_back(1);

	ll.show();

	cout << ll.front() << " " << ll.back() << endl;

	return 0;
}
