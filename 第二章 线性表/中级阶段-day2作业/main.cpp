#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void modify_pointer(char*& p)
{
	p = (char*)malloc(100);//����ռ�
	fgets(p, 100, stdin);//���ʹ��fgets�������һ��ָ��������м������ָ��ָ��Ŀռ��С
}

int main()
{
	char* p=NULL;
	modify_pointer(p);
	puts(p);
	return 0;
}