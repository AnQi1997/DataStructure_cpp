#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct TreeNode {
	DataType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode, * Tree;

typedef Tree LinkDataType;
//�洢���Ľ���ַ
typedef struct tag {
	Tree p;//����ĳһ������ֵַ
	struct  tag* pnext;
}tag_t, * ptag_t;
//���е�������ݽṹ

typedef struct LinkNode {
	LinkDataType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//��ʼ������
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else
	{
		return false;
	}
}
//����
void EnQueue(LinkQueue& Q, LinkDataType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x; s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
//����
bool DeQueue(LinkQueue& Q, LinkDataType& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	else
	{
		LinkNode* p = Q.front->next;//ͷ���ʲô��û�棬����ͷ������һ���ڵ��������
		x = p->data;
		Q.front->next = p->next;
		if (Q.rear == p) {
			Q.rear = Q.front;
			free(p);
			return true;
		}
	}
	return true; //����Ҫע�⣬���ӻ�wrong answer
}
//������ (�����ַ�����)
void BuildCharTree(Tree& T)
{
	Tree pnew;
	char x;
	ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;//phead ����ͷ ptail ����β
	while (scanf("%c", &x) != EOF)
	{
		if (x == '\n') {
			break;
		}
		//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		//��ʼ�����
		pnew = (Tree)calloc(1, sizeof(TreeNode));
		pnew->data = x;
		//�����н������ռ�
		listpnew = (ptag_t)calloc(1, sizeof(ptag_t));
		listpnew->p = pnew;

		if (NULL == T) {
			T = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
			continue;
		}
		else//T!=NULL
		{
			//���½���������β�巨
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		//pcurʼ��ָ��Ҫ����Ľ��λ��
		if (NULL == pcur->p->lchild) {
			//���½��ŵ�Ҫ����������
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild) {
			//���½��ŵ�Ҫ��������ұ�
			pcur->p->rchild = pnew;
			//���Ҷ����˽���pcurָ����е���һ��
			pcur = pcur->pnext;
		}
	}
}
//ǰ�����
void preOrder(Tree T)
{
	if (NULL != T) {
		putchar(T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}

}

//�������
void InOrder(Tree T)
{
	if (NULL != T) {
		InOrder(T->lchild);
		putchar(T->data);
		InOrder(T->rchild);
	}

}
//�������
void BackOrder(Tree T)
{
	if (NULL != T) {
		BackOrder(T->lchild);
		BackOrder(T->rchild);
		putchar(T->data);
	}

}

//��α���,���������������ȱ���
void LevelOrder(Tree T)
{
	LinkQueue Q;
	InitQueue(Q);
	Tree p;
	EnQueue(Q, T);//�������
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		putchar(p->data);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}
int main()
{
	Tree T = NULL;
	//��ν���  abcdefghij
	BuildCharTree(T);
	//ǰ�����
	//preOrder(T);
	//printf("\n");
	//�������
	InOrder(T);
	printf("\n");
	//�������
	BackOrder(T);
	printf("\n");
	//�������
	LevelOrder(T);
	return 0;
}
