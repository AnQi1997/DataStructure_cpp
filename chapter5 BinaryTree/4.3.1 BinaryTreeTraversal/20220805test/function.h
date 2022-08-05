/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-05 11:44:13
 * @Description: �����������Լ�д
 */
#include <stdio.h>
#include <stdlib.h>

//////////////////������
typedef char BiElemType;
typedef struct BNode {
    BiElemType c;
    struct BNode* lchild;
    struct BNode* rchild;
} BTNode, *BTree;

//�������� �Լ������ͷ��β
typedef struct tag {
    // BNode* p;  //ĳ�������ĵ�ַ����ָ��
    BTree p;
    struct tag* pnext;
} tag_t, *ptag_t;

//////////////////ջ
//��������ǵݹ��õ�
#define MaxSize 50
// typedef BNode ElemType;
typedef BTree ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;
}

//��ջ��
bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

//��ջ
bool Push(SqStack& S, ElemType x) {
    if (MaxSize - 1 == S.top)
        return false;
    S.data[++S.top] = x;
    return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

////////////////////����
//��α���ʹ��
//������
typedef struct LinkNode {
    ElemType data;
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
bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//���
void EnQueue(LinkQueue& Q, ElemType x) {
    //��β���
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;

    Q.rear->next = s;
    Q.rear = s;
}
//����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //��ͷ����
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;  // Q.rearǰ��
    free(p);
    return true;
}