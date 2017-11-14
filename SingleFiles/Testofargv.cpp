#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	printf("argc: %d\n", argc);
	puts(argv[0]);
	for (int i=1;i<argc;i++) {
		if (strcmp(argv[i],"-o") == 0) {
			//printf("-o\n");
			puts(argv[i]);
		} else if (strcmp(argv[i],"-Wall") == 0) {
			//printf("-Wall\n");
			puts(argv[i]);
		} else {
			
			printf("%s",argv[i]);
			printf(" Undefined\n");
		}
	}
	//system("pause");
	return 0;
}