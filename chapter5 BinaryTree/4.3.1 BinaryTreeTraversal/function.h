/*
 * @Author: 2361067080@qq.com
 * @Date: 2021-10-22 10:46:09
 * @Description: 
 */
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode {
    BiElemType c;  // c就是书籍上的data
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

//队列结构
typedef struct tag {
    BiTree p;  //树的某一个结点的地址值
    struct tag* pnext;
} tag_t, *ptag_t;

//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// void InitStack(SqStack& S);
// bool StackEmpty(SqStack& S);
// bool Push(SqStack& S, ElemType x);
// bool Pop(SqStack& S, ElemType& x);
// bool GetTop(SqStack& S, ElemType& x);
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

//队列的相关数据结构
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;
// void InitQueue(LinkQueue& Q);
// bool IsEmpty(LinkQueue Q);
// void EnQueue(LinkQueue& Q, ElemType x);
// bool DeQueue(LinkQueue& Q, ElemType& x);

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));  //头和尾指向同一个结点
    Q.front->next = NULL;                                    //头结点的next指针为NULL
}

bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//入队，尾部插入法
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;  // rear始终指向尾部
    Q.rear = s;
}

//出队  头部删除法
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;             //队列为空
    
    LinkNode* p = Q.front->next;  //头结点什么都没存，所以头结点的下一个节点才有数据
    x = p->data;
    
    Q.front->next = p->next;  //断链
    if (Q.rear == p)          //删除的是最后一个元素
        Q.rear = Q.front;     //队列置为空
    free(p);
    return true;
}