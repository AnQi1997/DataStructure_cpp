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
//存储树的结点地址
typedef struct tag {
	Tree p;//树的某一个结点地址值
	struct  tag* pnext;
}tag_t, * ptag_t;
//队列的相关数据结构

typedef struct LinkNode {
	LinkDataType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//初始化队列
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else
	{
		return false;
	}
}
//进队
void EnQueue(LinkQueue& Q, LinkDataType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x; s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
//出队
bool DeQueue(LinkQueue& Q, LinkDataType& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	else
	{
		LinkNode* p = Q.front->next;//头结点什么都没存，所以头结点的下一个节点才有数据
		x = p->data;
		Q.front->next = p->next;
		if (Q.rear == p) {
			Q.rear = Q.front;
			free(p);
			return true;
		}
	}
	return true; //这里要注意，不加会wrong answer
}
//层序建树 (放入字符的树)
void BuildCharTree(Tree& T)
{
	Tree pnew;
	char x;
	ptag_t phead = NULL, ptail = NULL, pcur = NULL, listpnew = NULL;//phead 队列头 ptail 队列尾
	while (scanf("%c", &x) != EOF)
	{
		if (x == '\n') {
			break;
		}
		//calloc申请空间并对空间进行初始化，赋值为0
		//初始化结点
		pnew = (Tree)calloc(1, sizeof(TreeNode));
		pnew->data = x;
		//给队列结点申请空间
		listpnew = (ptag_t)calloc(1, sizeof(ptag_t));
		listpnew->p = pnew;

		if (NULL == T) {
			T = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
			continue;
		}
		else//T!=NULL
		{
			//将新结点放入链表，尾插法
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		//pcur始终指向要插入的结点位置
		if (NULL == pcur->p->lchild) {
			//把新结点放到要插入结点的左边
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild) {
			//把新结点放到要插入结点的右边
			pcur->p->rchild = pnew;
			//左右都放了结点后，pcur指向队列的下一个
			pcur = pcur->pnext;
		}
	}
}
//前序遍历
void preOrder(Tree T)
{
	if (NULL != T) {
		putchar(T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}

}

//中序遍历
void InOrder(Tree T)
{
	if (NULL != T) {
		InOrder(T->lchild);
		putchar(T->data);
		InOrder(T->rchild);
	}

}
//后序遍历
void BackOrder(Tree T)
{
	if (NULL != T) {
		BackOrder(T->lchild);
		BackOrder(T->rchild);
		putchar(T->data);
	}

}

//层次遍历,层序遍历，广度优先遍历
void LevelOrder(Tree T)
{
	LinkQueue Q;
	InitQueue(Q);
	Tree p;
	EnQueue(Q, T);//树根入队
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
	//层次建树  abcdefghij
	BuildCharTree(T);
	//前序遍历
	//preOrder(T);
	//printf("\n");
	//中序遍历
	InOrder(T);
	printf("\n");
	//后序遍历
	BackOrder(T);
	printf("\n");
	//层序遍历
	LevelOrder(T);
	return 0;
}
