#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::priority_queue;
#ifndef INF
#define INF 0x7fffffff
#endif

struct edge {
	unsigned int fromindex;
	unsigned int toindex;
	unsigned int length;

	edge *next;
	edge *rnext;

	edge(unsigned int fromindex, unsigned int toindex, unsigned int length) 
	: fromindex(fromindex), toindex(toindex), length(length), next(nullptr), rnext(nullptr) {

	}

	bool operator <(edge &another) {
		return length < another.length;
	}

};

template<class Type>
struct vertex {
	Type data;
	edge *first;
	edge *rfirst;

	vertex(Type data) : data(data), first(nullptr), rfirst(nullptr) {

	}
};

struct lowestedge {
	unsigned int fromindex;
	unsigned int length;
};


template<class Type>
class AdjacentList {
private:
	std::vector< vertex<Type> > v;
	unsigned int edgenum;

public:
	AdjacentList() {
		edgenum=0u;
	}
	~AdjacentList() {
		edge *p=nullptr;
		edge *q=nullptr;
		for (unsigned int i=0;i<v.size();i++) {
			p=v[i].first;
			if (p==nullptr) {
				continue;
			} else {
				while (p->next!=nullptr) {
					q=p->next;
					delete p;
					p=q;
				}
				delete p;
			}
		}
	}

	void addVertex(const Type data) {
		for (unsigned int i=0;i<v.size();i++) {
			if (v[i].data==data) {
				return;
			}
		}
		v.push_back(vertex<Type>(data));
	}

	inline void addEdge_s(const Type &from, const Type &to, const unsigned int length=0u) {
		bool foundfrom=false;
		bool foundto=false;
		unsigned int fromindex;
		unsigned int toindex;

		for (unsigned int i=0;i<v.size();i++) {
			if (v[i].data==from) {
				foundfrom=true;
				fromindex=i;
			}
			if (v[i].data==to) {
				foundto=true;
				toindex=i;
			}
		}

		if (!foundfrom || !foundto) {
			return;
		}

		edge *p=v[fromindex].first;
		if (p==nullptr) {
			v[fromindex].first=new edge(fromindex, toindex, length);
		} else {
			while (p->next!=nullptr) {
				p=p->next;
			}
			p->next=new edge(fromindex, toindex, length);
		}
		++edgenum;

	}

	void addEdge(const Type from, const Type to, const unsigned int length=0u) {
		addEdge_s(from, to, length);
		addEdge_s(to, from, length);

	}

	void addEdge_directed(const Type from, const Type to, const unsigned int length=0u) {
		addEdge_s(from, to, length);
	}


	void showVertex() const {
		for (unsigned int i=0;i<v.size();i++) {
			cout << v[i].data << ", ";
		}
		cout << endl;
	}

	void showEdge() const {
		edge *p;
		for (unsigned int i=0;i<v.size();i++) {
			p=v[i].first;
			while (p!=nullptr) {
				if (p->toindex>=i)
					cout << v[p->fromindex].data << "->" << v[p->toindex].data << ", "; 
				p=p->next;
			}
			cout << endl;
		}
	}

	void PrimAlgorithm(const unsigned int index=0u) {
		lowestedge maxle;
		maxle.fromindex=0u;
		maxle.length=INF;
		vector<lowestedge> low(v.size(), maxle);
		vector<bool> visited(v.size(), false);

		edge *p;
		unsigned int nextindex=0u;
		unsigned int visitednum=0u;
		unsigned int currentindex=index;
		unsigned int lowestlength=INF;
		//unsigned int currentindexrecord=0u;
		
		while (visitednum<v.size()) {
			//cout << "currentindex: " << currentindex << endl;
			//currentindexrecord=currentindex;
			visited[currentindex]=true;
			if (visitednum>0u) {
				cout << "(" << v[low[currentindex].fromindex].data << ", " 
					<< v[currentindex].data << ", " 
					<< low[currentindex].length << ")" << endl;
			}

			++visitednum;

			p=v[currentindex].first;
			

			while (p!=nullptr) {
				if (!visited[p->toindex] && p->length<low[p->toindex].length) {
					low[p->toindex].fromindex=currentindex;
					low[p->toindex].length=p->length;
				}
				p=p->next;
			}

			lowestlength=INF;
			for (unsigned int i=0;i<low.size();i++) {
				if (!visited[i] && low[i].length < lowestlength) {
					currentindex=i;
					lowestlength=low[i].length;
				}
			}
			//currentindex=nextindex;

		}

	}

	void KruskalAlgorithm() {
		std::vector<edge> ve;
		std::vector<unsigned int> setid(v.size());
		edge *p;

		for (unsigned int i=0;i<v.size();i++) {
			setid[i]=i;
			p=v[i].first;
			while (p!=nullptr) {
				if (p->toindex > i) {
					ve.push_back(*p);
				}
				p=p->next;
			}
		}

		//cout << "Added edge! " << endl;

		sort(ve.begin(), ve.end());

		unsigned int currentindex=0u;
		unsigned int edgecount=0u;

		while (edgecount<v.size()-1) {
			if (setid[ve[currentindex].toindex]!=setid[ve[currentindex].fromindex]) {
				//setid[ve[currentindex].toindex]=setid[ve[currentindex].fromindex];
				for (unsigned int i=0;i<setid.size();i++) {
					if (setid[i]==setid[ve[currentindex].toindex]) {
						setid[i]=setid[ve[currentindex].fromindex];
					}
				}
				cout << "(" << v[ve[currentindex].fromindex].data << ", " 
					<< v[ve[currentindex].toindex].data << ", " 
					<< ve[currentindex].length << ")" << endl;
				++edgecount;
			}
			++currentindex;
		}


	}

private:
	bool compareEdge(edge &a, edge &b) {
		return (a.length < b.length);
	}

};


int main(int argc, char const *argv[])
{
	AdjacentList<string> al;
		al.addVertex("A");
		al.addVertex("B");
		al.addVertex("C");
		al.addVertex("D");
		al.addVertex("E");
		al.addVertex("F");

		al.addEdge("A", "B", 10);
		al.addEdge("B", "C", 12);
		al.addEdge("C", "D", 6);
		al.addEdge("D", "E", 8);
		al.addEdge("E", "F", 9);
		al.addEdge("A", "F", 18);
		al.addEdge("A", "D", 16);
		al.addEdge("A", "E", 8);
		al.addEdge("B", "D", 9);

		al.showVertex();
		al.showEdge();
		al.PrimAlgorithm(0);
		al.KruskalAlgorithm();

	return 0;
}