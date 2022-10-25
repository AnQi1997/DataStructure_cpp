/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-10-21 21:43:25
 * @Description:
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

//ջ
#define MaxSize 50
typedef BiTree ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//ջ
// InitStack
// StackEmpty
// Push
// Pop
// GetTop

void InitStack(SqStack& S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

bool Push(SqStack& S, ElemType x) {
    if (MaxSize - 1 == S.top)
        return false;     //ջ�����޷���ջ����false
    S.data[++S.top] = x;  //Ԫ�ؽ�ջ��ָ�������ƣ������Ԫ��
    return true;
}

bool Pop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

//����
typedef struct tag {
    BiTree p;  //����ĳ�����ĵ�ַ
    struct tag* pnext;
} tag_t, *ptag_t;

//���н��
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;
//���нṹ
typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue& Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}



