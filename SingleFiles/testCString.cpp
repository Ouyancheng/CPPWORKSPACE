#include <cstdio>
using namespace std;
int main() {
	const char *const str = "Hello";
	char *str2 = (char *)str;
	str2[0] = 'A';
	printf("%s\n", str2);
	return 0;
}