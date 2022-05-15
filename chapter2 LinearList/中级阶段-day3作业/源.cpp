#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
bool ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)//是把数据往后移动
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;//要插入的数据放入到对应的位置上去
	L.length++;
	return true;
}
bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)//把数据往前移动
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
void PrintList(SqList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}
//要不要加引用，就是看是不是在子函数中去改变主函数中对应的变量，要改，就要加，不加，不需要改
int main()
{
	SqList L;
	bool ret_1;
	bool ret_2;
	ElemType del;
	int add_p;
	int del_p;
	scanf("%d", &add_p);//读取添加的元素值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	ret_1 = ListInsert(L, 2, add_p);//读取的元素固定放在第二个位置的
	if (ret_1)
	{
		PrintList(L);
	}
	else {
		printf("false\n");
	}
	scanf("%d", &del_p);//读取删除元素的位置
	ret_2 = ListDelete(L, del_p, del);
	if (ret_2)
	{
		PrintList(L);
	}
	else {
		printf("false\n");
	}
}
