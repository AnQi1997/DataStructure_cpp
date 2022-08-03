/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-03 18:13:19
 * @Description: 二叉树遍历的头文件-抄
 */
#include <stdio.h>
#include <stdlib.h>

//二叉树
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

//栈
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

//进栈
bool Push(SqStack& S, Elemtype x) {
    if (MaxSize - 1 == S.top)
        return false;
    S.data[++S.top] = x;
    return true;
}

//出栈
bool Pop(SqStack& S, Elemtype& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack& S, Elemtype& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

//队列
typedef struct LinkNode {
    Elemtype data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

//初始化
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判队空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//进队
void EnQueue(LinkQueue& Q, Elemtype x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;

    Q.rear->next = s;
    Q.rear = s;
}

//出队
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
