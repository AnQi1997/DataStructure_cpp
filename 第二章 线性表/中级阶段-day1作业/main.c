#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	int num;
	char name[20];
	char sex;
};//����һ���ṹ������

int main()
{
	struct student s;
	scanf("%d%s %c", &s.num, s.name, &s.sex);//scanf����ʱ��Ϊʲô����Ҫ��һ����ַ��ָ��Ĵ��ݵ�ʹ�ó���
	printf("%d %s %c\n", s.num, s.name, s.sex);
	return 0;
}