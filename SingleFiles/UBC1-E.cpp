#include <iostream>
#include <vector>
using namespace std;

struct cannon {
	int t;
	int s,c,d,w;

	int total;
	cannon(int t, int s, int c, int d, int w)
	: t(t), s(s), c(c), d(d), w(w) {
		total=s+c;
	}
};

int main() {
	int cases;
	int x,y,h1,h2;
	vector<cannon> a;
	vector<cannon> b;
	int t,s,c,d,w;
	
	cin >> cases;
	int time;
	for (int ci=0;ci<cases;ci++) {
		cin >> x >> y >> h1 >> h2;
		time=0;
		a.clear();
		b.clear();
		for (int i=0;i<x;i++) {
			cin>>t>>s>>c>>d>>w;
			a.push_back(cannon(t,s,c,d,w));
		}
		for (int i=0;i<y;i++) {
			cin>>t>>s>>c>>d>>w;
			b.push_back(cannon(t,s,c,d,w));
		}
		
		int xdm,ydm;
		bool xh2,yh2;
		bool xdom;
		while (h1>0 && h2>0) {
			time++;
			xdm=ydm=0;
			xh2=yh2=false;
			xdom=true;
			for (int i=0;i<x;i++) {
				a[i].total--;
				if (a[i].total==0) {
					xdm+=a[i].d;
					if (a[i].t==2) {
						xh2=true;
					}
					a[i].total=a[i].c+a[i].w;
				}
				
			}
			
			for (int i=0;i<y;i++) {
				b[i].total--;
				if (b[i].total==0) {
					ydm+=b[i].d;
					if (b[i].t==2) {
						yh2=true;
					}
					b[i].total=b[i].c+b[i].w;
				}
				
			}
			
			if (xdm > ydm) {
				xdom=true;
			} else if (xdm < ydm) {
				xdom=false;
			} else {
				if (h1>h2) {
					xdom=true;
				} else if (h1<h2) {
					xdom=false;
				} else {
					xdom=true;
				}
			}
			
			if (xdom==true) {
				if (xh2==true) {
					for (int i=0;i<y;i++) {
						if (b[i].total<=b[i].c) {
							b[i].total=b[i].c;
						}
					}
					//h2-=xdm;
				}
				h2-=xdm;
			} else {
				if (yh2==true) {
					for (int i=0;i<x;i++) {
						if (a[i].total<=a[i].c) {
							a[i].total=a[i].c;
						}
					}
					//h1-=ydm;
				}
				h1-=ydm;
			}
			
			if (h2<=0) {
				cout << "A " << time << endl;
				break;
			}
			if (h1<=0) {
				cout << "B " << time << endl;
				break;
			}
			
		}
	}
	
	return 0;
} 
