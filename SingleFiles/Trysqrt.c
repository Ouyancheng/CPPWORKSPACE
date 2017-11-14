#include <stdio.h>
#include <math.h>
#ifndef EPS
#define EPS 1.0E-8
#endif
int main() {
	double x,y,oldY;
	double ave;

	printf("Enter a positive number: ");
	scanf("%lf", &x);

	y = 1.0;
	oldY = 0.0;

	//if (x >= 0.0 && x < EPS) {
	if (x == 0.0) {
		printf("Square root: %d\n", 0.0);
	} else if (x < 0.0) {
		printf("Please enter a positive number.\n");
	} else {
		while (fabs(oldY - y) > (0.00001 * y)) {
			oldY = y;

			y = (y + x/y) / 2.0;
			//y = ave;
		}
		printf("Square root: %.5lf", y);
	}

	return 0;
}