/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-03 18:13:19
 * @Description: ������������ͷ�ļ�-��
 */
#include <stdio.h>
#include <stdlib.h>

//������
typedef char BiElemType;
typedef struct BiTNode {
    BiElemType c;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

typedef struct tag {
    BiTree p;
    struct tag* pnext;
} tag_t, *ptag_t;

//ջ
#define MaxSize 50
typedef BiTree Elemtype;
typedef struct {
    Elemtype data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack& S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

//��ջ
bool Push(SqStack& S, Elemtype x) {
    if (MaxSize - 1 == S.top)
        return false;
    S.data[++S.top] = x;
    return true;
}

//��ջ
bool Pop(SqStack& S, Elemtype& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack& S, Elemtype& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

//����
typedef struct LinkNode {
    Elemtype data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

//��ʼ��
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//�жӿ�
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//����
void EnQueue(LinkQueue& Q, Elemtype x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;

    Q.rear->next = s;
    Q.rear = s;
}

//����
bool DeQueue(LinkQueue& Q, Elemtype& x) {
    if (Q.rear == Q.front)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}
