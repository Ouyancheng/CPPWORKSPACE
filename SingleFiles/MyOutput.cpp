#include <cstdio>
#include <string>
#include <iostream>
#include <ctime>

class output {
public:
	output & operator << (const std::string &str) {
		for (unsigned int i=0;i<str.size();i++) {
			putchar(*(&str[0]+i));
		}
		return (*this);
	}
	
	output & operator << (const char &c) {
		putchar(c);
		return (*this);
	}
	
	output & operator << (const char *cstr) {
		int i=0;
		while ((cstr[i])!='\0') {
			putchar(cstr[i]);
			++i;
		}
		return (*this);
	}
	
	output & operator << (int i) {
		printf("%d", i);
		return (*this);
	}
	
	output & operator << (short i) {
		printf("%d", i);
		return (*this);
	}
	
	output & operator << (long int i) {
		printf("%ld", i);
		return (*this);
	}
	
	output & operator << (long long int i) {
		printf("%lld", i);
		return (*this);
	}
	
	output & operator << (bool b) {
		if (b==true) {
			puts("true");
		} else {
			puts("false");
		}
		return (*this);
	}
	
	output & operator << (double d) {
		printf("%lf", d);
		return (*this);
	}
	
	output & operator << (long double d) {
		printf("%Lf", d);
		return (*this);
	}
	
	output & operator << (float f) {
		printf("%f", f);
		return (*this);
	}
	
	output & operator << (void (*function)()) {
		function();
		return (*this);
	}
	
	
};

void endl() {
	putchar('\n');
}

int main() {
	int n=10;
	std::string str("ut");
	output opt;
	//opt << i  << " " << "I love APU" << " " << 'B' << str << endl;
	
	clock_t begin;
	clock_t end;
	
	begin=clock();
	for (int i=0;i<100000;i++) {
		//opt << i << endl;
		printf("%c", 'S');
	}
	end=clock();
	std::cout << "\n1pTime: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
	system("pause");
	
	begin=clock();
	for (int i=0;i<100000;i++) {
		//std::cout << i << std::endl;
		printf("%c", 'S'); 
		//opt << i << endl;
	}
	end=clock();
	std::cout << "\n2pTime: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
	system("pause");
	
	
	begin=clock();
	for (int i=0;i<100000;i++) {
		//std::cout << i << std::endl;
		//printf("%d", i); 
		opt << (char)('S');
	}
	end=clock();
	std::cout << "\noptTime: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
	system("pause");
	
	begin=clock();
	for (int i=0;i<100000;i++) {
		std::cout << (char)('S');
		//printf("%d", i); 
		//opt << i << endl;
	}
	end=clock();
	std::cout << "\ncoutTime: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
	system("pause");
	
	begin=clock();
	for (int i=0;i<100000;i++) {
		//std::cout << i << std::endl;
		//printf("%d", i); 
		//opt << (char)('S');
		putchar('S');
	}
	end=clock();
	std::cout << "\npcTime: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
	system("pause");
	
	return 0;
}
