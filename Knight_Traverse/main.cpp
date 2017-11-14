/*
 * main.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: ouyan
 */

#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define S 6
int chess[S][S];


bool nextxy(int &x, int &y, int count) {
	switch (count) {
	case 1:
		if (x-2>=0 && y-1>=0 && chess[x-2][y-1]==0) {
			x-=2;
			y-=1;
			return true;
		}
		break;

	case 2:
		if (x-2>=0 && y+1<S && chess[x-2][y+1]==0) {
			x-=2;
			y+=1;
			return true;
		}
		break;

	case 3:
		if (x-1>=0 && y+2<S && chess[x-1][y+2]==0) {
			x-=1;
			y+=2;
			return true;
		}
		break;

	case 4:
		if (x+1<S && y+2<S && chess[x+1][y+2]==0) {
			x+=1;
			y+=2;
			return true;
		}
		break;

	case 5:
		if (x+2<S && y+1<S && chess[x+2][y+1]==0) {
			x+=2;
			y+=1;
			return true;
		}
		break;

	case 6:
		if (x+2<S && y-1>=0 && chess[x+2][y-1]==0) {
			x+=2;
			y-=1;
			return true;
		}
		break;

	case 7:
		if (x+1<S && y-2>=0 && chess[x+1][y-2]==0) {
			x+=1;
			y-=2;
			return true;
		}
		break;

	case 8:
		if (x-1>=0 && y-2>=0 && chess[x-1][y-2]==0) {
			x-=1;
			y-=2;
			return true;
		}
		break;

	default:
		break;

	}
	return false;
}

void printchessboard() {
	for (int i=0;i<S;i++) {
		for (int j=0;j<S;j++) {
			printf("%02d ", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool KnightTraverse(int x, int y, int step) {
	printf("%d Trying to jump to (%d,%d)!\n", step, x, y);

	chess[x][y]=step;
	if (step==S*S) {
		printchessboard();
		//exit(0);
		return true;
	}

	int x1=x, y1=y;
	int count=1;
	bool foundnext=false;
	foundnext=nextxy(x1, y1, count);
	while (foundnext==false && count<8) {
		printf("x1=%d y1=%d failed! count=%d\n", x1, y1, count);
		++count;
		foundnext=nextxy(x1, y1, count);
	}
	printf("x1=%d y1=%d %d\n", x1, y1, foundnext);

	while (foundnext==true) {
		if (KnightTraverse(x1, y1, step+1)==true) {
			return true;
		}

		x1=x;
		y1=y;
		++count;
		foundnext=nextxy(x1, y1, count);
		while (foundnext==false && count<8) {
			++count;
			foundnext=nextxy(x1, y1, count);
		}
	}

	if (foundnext==false) {
		chess[x][y]=0;
	}
	return false;
}

int main() {
	for (int i=0;i<S;i++) {
		for (int j=0;j<S;j++) {
			chess[i][j]=0;
		}
	}
	clock_t start;
	clock_t finish;
	start=clock();
	printf("%d\n", KnightTraverse(0, 0, 1));
	finish=clock();
	printf("Time used: %fs", (double)(finish-start)/CLOCKS_PER_SEC);
	//getchar();
	return 0;
}


