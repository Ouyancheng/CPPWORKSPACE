#include <iostream>
#include <cstdlib>
using namespace std;

int a[1000][1000];
int f[1000][1000];
int n,m,l,r;
void dfs(int i, int j, int weight) {
	weight+=a[i][j];
	if (i>=n || j>=m) {
		return;
	}
	if (i==n && j==m && l<=weight && r>=weight) {
		cout << "Yes" << endl;
		exit(0);
	}
	if (weight>=l && weight<=r) {
		dfs(i+1, j, weight);
		dfs(i, j+1, weight);
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int ci=0;ci<cases;ci++) {
		cin >> n >> m >> l >> r;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				cin >> a[i][j];
			}
		}
		
		dfs(0,0,a[0][0]);
		
		cout << "No" << endl;
		
	}
	return 0;
}
