#include <stdio.h>
//#include <stdlib.h>

int max(int x, int y) {
	return x>y?x:y;
}

int min(int x, int y) {
	return x<y?x:y;
}

int main() {
	int x;
	int y;
	int n;

	int xmax=-999999;
	int ymax=-999999;
	int xmin=999999;
	int ymin=999999;
	scanf("%d",&n);

	int i=1;
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		scanf("%d",&y);
		xmax=max(x,xmax);
		ymax=max(y,ymax);
		xmin=min(x,xmin);
		ymin=min(y,ymin);
	}

	printf("%d %d %d %d", xmin, ymin, xmax, ymax);

	//system("pause");

	return 0;
}