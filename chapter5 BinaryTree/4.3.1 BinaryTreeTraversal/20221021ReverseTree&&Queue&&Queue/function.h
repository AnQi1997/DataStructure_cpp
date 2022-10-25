/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-10-21 21:43:25
 * @Description:
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

//栈
#define MaxSize 50
typedef BiTree ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//栈
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
        return false;     //栈满，无法进栈返回false
    S.data[++S.top] = x;  //元素进栈，指针先上移，后放入元素
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

//队列
typedef struct tag {
    BiTree p;  //树的某个结点的地址
    struct tag* pnext;
} tag_t, *ptag_t;

//队列结点
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;
//队列结构
typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue& Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}



