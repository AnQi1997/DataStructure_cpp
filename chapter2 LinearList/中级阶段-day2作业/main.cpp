#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void modify_pointer(char*& p)
{
	p = (char*)malloc(100);//申请空间
	fgets(p, 100, stdin);//如果使用fgets传入的是一个指针变量，中间参数是指针指向的空间大小
}

int main()
{
	char* p=NULL;
	modify_pointer(p);
	puts(p);
	return 0;
}