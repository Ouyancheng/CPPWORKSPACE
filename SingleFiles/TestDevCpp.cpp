#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	string cstr;
	char *pstr;
	pstr=(char *)malloc(10*sizeof(char));
	scanf("%s", pstr);
	cstr.assign(pstr);
	printf("Hello World!\n");
	printf("%s\n", cstr.c_str());
	free(pstr);
	
	return 0;
}
