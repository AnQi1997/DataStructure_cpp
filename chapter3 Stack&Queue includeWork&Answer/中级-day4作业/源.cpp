#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;//指向下一个结点 
}LNode, * LinkList;
//头插法新建链表
LinkList CreatList1(LinkList& L)//list_head_insert
{
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//带头结点的链表
	L->next = NULL;//L->data里边没放东西
	scanf("%d", &x);//从标准输入读取数据
	//3 4 5 6 7 9999
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));//申请一个新空间给s，强制类型转换
		s->data = x;//把读取到的值，给新空间中的data成员
		s->next = L->next;//让新结点的next指针指向链表的第一个元素（第一个放我们数据的元素）
		L->next = s;//让s作为第一个元素
		scanf("%d", &x);//读取标准输入
	}
	return L;
}
//尾插法新建链表
LinkList CreatList2(LinkList& L)//list_tail_insert
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//带头节点的链表
	LNode* s, * r = L;//LinkList s,r=L;也可以，r代表链表表尾结点，指向链表尾部
	//3 4 5 6 7 9999
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;//让尾部结点指向新结点
		r = s;//r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;//尾结点的next指针赋值为NULL
	return L;
}


//打印链表中每个结点的值
void PrintList(LinkList L)
{
	L = L->next;//让L指向第一个有数据的结点
	while (L != NULL)
	{
		printf("%d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");

}
//《王道C督学营》课程

int main()
{
	LinkList L = NULL;//链表头，是结构体指针类型
	LinkList search;//用来存储拿到的某一个节点
	CreatList1(L);//输入数据可以为3 4 5 6 7 9999,头插法新建链表
	PrintList(L);//链表打印
	CreatList2(L);//输入数据可以为3 4 5 6 7 9999
	PrintList(L);
	return 0;
}