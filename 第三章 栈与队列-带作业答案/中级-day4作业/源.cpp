#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;//ָ����һ����� 
}LNode, * LinkList;
//ͷ�巨�½�����
LinkList CreatList1(LinkList& L)//list_head_insert
{
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//��ͷ��������
	L->next = NULL;//L->data���û�Ŷ���
	scanf("%d", &x);//�ӱ�׼�����ȡ����
	//3 4 5 6 7 9999
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));//����һ���¿ռ��s��ǿ������ת��
		s->data = x;//�Ѷ�ȡ����ֵ�����¿ռ��е�data��Ա
		s->next = L->next;//���½���nextָ��ָ������ĵ�һ��Ԫ�أ���һ�����������ݵ�Ԫ�أ�
		L->next = s;//��s��Ϊ��һ��Ԫ��
		scanf("%d", &x);//��ȡ��׼����
	}
	return L;
}
//β�巨�½�����
LinkList CreatList2(LinkList& L)//list_tail_insert
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//��ͷ�ڵ������
	LNode* s, * r = L;//LinkList s,r=L;Ҳ���ԣ�r���������β��㣬ָ������β��
	//3 4 5 6 7 9999
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;//��β�����ָ���½��
		r = s;//rָ���µı�β���
		scanf("%d", &x);
	}
	r->next = NULL;//β����nextָ�븳ֵΪNULL
	return L;
}


//��ӡ������ÿ������ֵ
void PrintList(LinkList L)
{
	L = L->next;//��Lָ���һ�������ݵĽ��
	while (L != NULL)
	{
		printf("%d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");

}
//������C��ѧӪ���γ�

int main()
{
	LinkList L = NULL;//����ͷ���ǽṹ��ָ������
	LinkList search;//�����洢�õ���ĳһ���ڵ�
	CreatList1(L);//�������ݿ���Ϊ3 4 5 6 7 9999,ͷ�巨�½�����
	PrintList(L);//�����ӡ
	CreatList2(L);//�������ݿ���Ϊ3 4 5 6 7 9999
	PrintList(L);
	return 0;
}