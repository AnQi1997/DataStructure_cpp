#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	int num;
	char name[20];
	char sex;
};//声明一个结构体类型

int main()
{
	struct student s;
	scanf("%d%s %c", &s.num, s.name, &s.sex);//scanf传递时，为什么后面要给一个地址，指针的传递的使用场景
	printf("%d %s %c\n", s.num, s.name, s.sex);
	return 0;
}