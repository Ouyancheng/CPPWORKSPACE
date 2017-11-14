#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	int fromindex;
	int length;
} lownode;

point *v;

int distance(int fromindex, int toindex) {
	return (abs(v[fromindex].x - v[toindex].x) + abs(v[fromindex].y - v[toindex].y));
}

void PrimAlgorithm(int n, point *v) {
	int currentindex = 0;

	lownode *lowest;
	lowest = (lownode *)malloc(n * sizeof(lownode));

	for (int i=0;i<n;i++) {
		lowest[i].fromindex = 0;
		lowest[i].length = distance(0, i);
	}

	bool *visited;
	visited = (bool *)malloc(n * sizeof(bool));
	for (int i=0;i<n;i++) {
		visited[i]=0;
	}


	int visitednumber = 0;
	int smallest = 0x7fffffff;

	while (visitednumber < n - 1) {
		visited[currentindex] = 1;
		for (int i=0;i<n;i++) {
			if (!visited[i] && (distance(i, currentindex) < lowest[i].length)) {
				lowest[i].length = distance(i, currentindex);
				lowest[i].fromindex = currentindex;
			}
		}

		for (int i=0;i<n;i++) {
			if (!visited[i] && (lowest[i].length < smallest)) {
				smallest=lowest[i].length;
				currentindex = i;
			}
		}

		smallest = 0x7fffffff;
		++visitednumber;
		//if (visitednumber <= 19)
		printf("%d %d %d\n", lowest[currentindex].fromindex, currentindex, lowest[currentindex].length);

		
	}

	free(visited);
	free(lowest);
}

int main() {
	int num_pt;
	scanf("%d", &num_pt);

	v = (point *)malloc(num_pt * sizeof(point));

	for (int i=0;i<num_pt;i++) {
		scanf("%d%d", &(v[i].x), &(v[i].y));
	}

	PrimAlgorithm(num_pt, v);

	free(v);

	return 0;
}





