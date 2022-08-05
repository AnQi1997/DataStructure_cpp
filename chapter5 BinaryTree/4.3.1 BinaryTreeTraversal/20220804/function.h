#include <stdio.h>
#include <stdlib.h>

//二叉树
typedef char BiElemType;
typedef struct BiNode {
    BiElemType c;
    struct BiNode* lchild;
    struct BiNode* rchild;
} BiTNode, *BiTree;

//辅助队列
typedef struct tag {
    BiTree p;
    struct tag* pnext;
} tag_t, *ptag_t;

//栈
#define MaxSize 50
typedef BiTree ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;
//初始化
void InitStack(SqStack& S) {
    S.top = -1;
}
//判栈空
bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}
//进栈
bool Push(SqStack& S, ElemType x) {
    if (MaxSize - 1 == S.top)
        return false;
    S.data[++S.top] = x;
    return true;
}

//出栈
bool Pop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

//队列
typedef struct LinkNode {
    ElemType data;
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

//判空
bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//进队
void EnQueue(LinkQueue& Q, ElemType x) {
    //链队列不存在溢出的情况
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    // return true;
}
//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
        // Q.front = Q.rear;
        //这一句倒过来会有什么结果？
    free(p);
    return true;
}