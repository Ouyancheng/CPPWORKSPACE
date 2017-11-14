#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

template <int n>
struct fib
{
	enum { value = fib<n - 1>::value + fib<n - 2>::value };
};

template <>
struct fib<1>
{
	enum { value = 1 };
};

template <>
struct fib<0>
{
	enum { value = 0 };
};

int _stdcall main()
{
	clock_t start, finish;

	start = clock();
	unsigned long long int n = fib<36>::value;
	cout << n << endl;
	finish = clock();

	cout << "Time usage: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	/*start = clock();
	for (unsigned int i = 0; i < 10000u; i++)
	{
		printf("Hello World! \n");
		//cout << "Hello World!" << endl;
	}
	finish = clock();
	printf("Time usage: %f\n", (double)(finish - start) / CLOCKS_PER_SEC);

	system("pause");

	//cout.sync_with_stdio(false);
	start = clock();
	for (unsigned int i = 0; i < 10000u; i++)
	{
		cout << "Hello World! " << endl;
	}
	finish = clock();
	cout << "Time usage: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;*/

	system("pause");

	
	return 0;
}


