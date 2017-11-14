#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main() {
	char a[256];
	int i = 0;
	char temp;
	scanf("%c",&temp);
	while (temp != '#') {
		a[i]=temp;
		i++;
		scanf("%c",&temp);
	}

	int n;
	scanf("%d",&n);
	int length;
	length=i;
	int j;

	j=0;

	for (i=1;i<=n;i++) {
		j--;
		if (j<0) {
			j=length-1;
		}

	}

	//printf("%d\n", length);

	//printf("%d\n", j);
	for (i=j;i<length;i++) {
		printf("%c", a[i]);
	}
	for (i=0;i<j;i++) {
		printf("%c", a[i]);
	}

	//system("pause");

	return 0;
}