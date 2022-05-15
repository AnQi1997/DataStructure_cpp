#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;//ָ����һ����� 
}LNode,*LinkList;
//ͷ�巨�½�����
LinkList CreatList1(LinkList &L)//list_head_insert
{
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));//��ͷ��������
	L->next=NULL;//L->data���û�Ŷ���
	scanf("%d",&x);//�ӱ�׼�����ȡ����
	//3 4 5 6 7 9999
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));//����һ���¿ռ��s��ǿ������ת��
		s->data=x;//�Ѷ�ȡ����ֵ�����¿ռ��е�data��Ա
		s->next=L->next;//���½���nextָ��ָ������ĵ�һ��Ԫ�أ���һ�����������ݵ�Ԫ�أ�
		L->next=s;//��s��Ϊ��һ��Ԫ��
		scanf("%d",&x);//��ȡ��׼����
	}
	return L;
}
//β�巨�½�����
LinkList CreatList2(LinkList &L)//list_tail_insert
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));//��ͷ�ڵ������
	LNode* s, * r = L;//LinkList s,r=L;Ҳ���ԣ�r���������β��㣬ָ������β��
	//3 4 5 6 7 9999
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;//��β�����ָ���½��
		r=s;//rָ���µı�β���
		scanf("%d",&x);
	}
	r->next=NULL;//β����nextָ�븳ֵΪNULL
	return L;
}
//����Ų��ҽ��ֵ
LNode *GetElem(LinkList L,int i)
{
	int j=1;
	LNode *p=L->next;
	if(i==0)
		return L;
	if(i<1)
		return NULL;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}
//��ֵ����
LNode *LocateElem(LinkList L,ElemType e)
{
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;
}
//�½������i��λ��
bool ListFrontInsert(LinkList L,int i,ElemType e)
{
	LinkList p=GetElem(L,i-1);
	if(NULL==p)
	{
		return false;
	}
	LinkList s=(LNode*)malloc(sizeof(LNode));//Ϊ�²���Ľ������ռ�
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//ɾ����i�����
bool ListDelete(LinkList L,int i)
{
	LinkList p=GetElem(L,i-1);
	if(NULL==p)
	{
		return false;
	}
	LinkList q;
	q=p->next;
	p->next=q->next;//����
	free(q);//�ͷŶ�Ӧ���Ŀռ�
	return true;
}
//��ӡ������ÿ������ֵ
void PrintList(LinkList L)
{
	L=L->next;
	while(L!=NULL)//NULL��Ϊ�˴���һ�ſյĲر�ͼ
	{
		printf("%3d",L->data);//��ӡ��ǰ�������
		L=L->next;//ָ����һ�����
	}
	printf("\n");
}
//������C��ѧӪ���γ�
//2.3 ���Ա����ʽ��ʾ
int main()
{
	LinkList L;//����ͷ���ǽṹ��ָ������
	LinkList search;//�����洢�õ���ĳһ���ڵ�
	//CreatList1(L);//�������ݿ���Ϊ3 4 5 6 7 9999,ͷ�巨�½�����
	CreatList2(L);//�������ݿ���Ϊ3 4 5 6 7 9999
	PrintList(L);//�����ӡ
	search=GetElem(L,2);
	//if(search!=NULL)
	//{
	//	printf("����Ų��ҳɹ�\n");
	//	printf("%d\n",search->data);
	//}
	search=LocateElem(L,6);//��ֵ��ѯ
	//if(search!=NULL)
	//{
	//	printf("��ֵ���ҳɹ�\n");
	//	printf("%d\n",search->data);
	//}
	ListFrontInsert(L,2,99);//�½������i��λ��
	//PrintList(L);
	//ListDelete(L,4);//ɾ����4�����
	//PrintList(L);
}