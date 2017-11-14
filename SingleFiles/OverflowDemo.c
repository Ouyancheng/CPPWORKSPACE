#include <stdio.h>
#include <stdlib.h>
void why_it_run() {
	printf("Why it runs?! \n");
	exit(0);
}

void overflow_func() {
	int a[2];
	a[0] = 1;
	a[1] = 2;
	for (size_t i = 3; i < 5; i++) {
		*(a + i) = (int)why_it_run; // Using *(a + i) instead of a[i] can avoid clang's overflow warning. 
	}
	return;
}

int main(int argc, char **argv) {
	overflow_func();
	return 0;
}