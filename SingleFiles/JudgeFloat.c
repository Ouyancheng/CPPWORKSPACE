#include <stdio.h>
//#include <stdlib.h>

int max(int a, int b) {
	return a>b?a:b;
}

int min(int a, int b) {
	return a<b?a:b;
}

int gcd(int a, int b) {
	if (a%b!=0) {
		return gcd(b,a%b);
	} else {
		return b;
	}
}

long long int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

int main() {
	int a1;
	int a2;
	int b1;
	int b2;

	scanf("%d/%d %d/%d", &a1, &a2, &b1, &b2);

	long long int l;
	l=lcm(max(a2,b2),min(a2,b2));


	long long int ta1=a1*(l/a2);
	long long int tb1=b1*(l/b2);

	if (ta1 > tb1) {
		printf("%d/%d > %d/%d", a1, a2, b1, b2);
	} else if (ta1 < tb1) {
		printf("%d/%d < %d/%d", a1, a2, b1, b2);
	} else {
		printf("%d/%d = %d/%d", a1, a2, b1, b2);
	}

	//system("pause");
	return 0;
}