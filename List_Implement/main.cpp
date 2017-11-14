/*
 * main.c
 *
 *  Created on: Jul 20, 2016
 *      Author: ouyan
 */

#include "List_Struct.h"
#include <stdio.h>

int main() {
	struct List a;
	InitList(6,&a);

	//int i=0;

	printf("Length: %d, Size: %d \n",a.length,a.size);
	push_back(1,&a);
	push_back(2,&a);
	push_back(3,&a);
	push_back(6,&a);
	push_back(8,&a);
	push_back(9,&a);
	push_back(10,&a);
	printf("Length: %d, Size: %d \n",a.length,a.size);
	insertElem(8,6,&a);
	printf("Length: %d, Size: %d, a[6]: %d \n",a.length,a.size,a.a[6]);

	push_back(11,&a);
	push_back(12,&a);
	push_back(16,&a);
	push_back(18,&a);
	push_back(19,&a);
	printf("Length: %d, Size: %d \n",a.length,a.size);

	system("pause");

	return 0;
}


