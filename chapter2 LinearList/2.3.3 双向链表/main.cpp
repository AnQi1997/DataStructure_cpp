#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;//ǰ�������
}DNode,*DLinkList;
//˫������ͷ�巨
DLinkList Dlist_head_insert(DLinkList &DL)
{
	DNode *s;int x;
	DL=(DLinkList)malloc(sizeof(DNode));//��ͷ��������DL����ͷ���
	DL->next=NULL;//ǰ��ָ��ͺ��ָ�붼��дΪNULL
	DL->prior=NULL;
	scanf("%d",&x);//�ӱ�׼�����ȡ����
	//3 4 5 6 7 9999
	while(x!=9999){
		s=(DLinkList)malloc(sizeof(DNode));//����һ���ռ�ռ䣬ǿ������ת��
		s->data=x;
		s->next=DL->next;
		if(DL->next!=NULL)//�����һ�����ʱ������Ҫ��һ������
		{
			DL->next->prior=s;
		}
		s->prior=DL;//Ҫ����Ľ��ָ��ͷ���
		DL->next=s;
		scanf("%d",&x);//��ȡ��׼����
	}
	return DL;
}
//˫������β�巨
DLinkList Dlist_tail_insert(DLinkList &DL)
{
	int x;
	DL=(DLinkList)malloc(sizeof(DNode));//��ͷ�ڵ������
	DNode *s,*r=DL;//r����βָ��
	DL->prior=NULL;
	//3 4 5 6 7 9999
	scanf("%d",&x);
	while(x!=9999){
		s=(DNode*)malloc(sizeof(DNode));
		s->data=x;
		r->next=s;
		s->prior=r;
		r=s;//rָ���µı�β���
		scanf("%d",&x);
	}
	r->next=NULL;//β����nextָ�븳ֵΪNULL
	return DL;
}
//����Ų��ҽ��ֵ
DNode *GetElem(DLinkList DL,int i)
{
	int j=1;
	DNode *p=DL->next;
	if(i==0)
		return DL;
	if(i<1)
		return NULL;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}
//�½������i��λ��
bool DListFrontInsert(DLinkList DL,int i,ElemType e)
{
	DLinkList p=GetElem(DL,i-1);//��ǰһ��λ�õĵ�ַ
	if(NULL==p)
	{
		return false;
	}
	DLinkList s=(DLinkList)malloc(sizeof(DNode));//Ϊ�²���Ľ������ռ�
	s->data=e;
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//ɾ����i�����
bool DListDelete(DLinkList DL,int i)
{
	DLinkList p=GetElem(DL,i-1);
	if(NULL==p)
	{
		return false;
	}
	DLinkList q;
	q=p->next;
	if(q==NULL)//ɾ����Ԫ�ز�����
		return false;
	p->next=q->next;//����
	if(q->next!=NULL)//q->nextΪNULLɾ���������һ�����
	{
		q->next->prior=p;
	}
	free(q);//�ͷŶ�Ӧ���Ŀռ�
	return true;
}
//�����ӡ
void PrintDList(DLinkList DL)
{
	DL=DL->next;
	while(DL!=NULL)
	{
		printf("%3d",DL->data);
		DL=DL->next;
	}
	printf("\n");
}

//������C��ѧӪ���γ�
//2.3.3 ˫������ɾ��
int main()
{
	DLinkList DL;
	DLinkList search;
	//Dlist_head_insert(DL);//ͷ������
	Dlist_tail_insert(DL);//β������
	//3 4 5 6 7 9999
	PrintDList(DL);
	search=GetElem(DL,2);
	if(search!=NULL)
	{
		printf("����Ų��ҳɹ�\n");
		printf("%d\n",search->data);
	}
	DListFrontInsert(DL,3,99);
	PrintDList(DL);
	DListDelete(DL,2);
	PrintDList(DL);
	return 0;
}