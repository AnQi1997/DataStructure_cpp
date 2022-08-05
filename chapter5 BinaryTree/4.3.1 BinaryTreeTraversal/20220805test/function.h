/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-08-05 11:44:13
 * @Description: 二叉树遍历自己写
 */
#include <stdio.h>
#include <stdlib.h>

//////////////////二叉树
typedef char BiElemType;
typedef struct BNode {
    BiElemType c;
    struct BNode* lchild;
    struct BNode* rchild;
} BTNode, *BTree;

//辅助链表 自己定义表头表尾
typedef struct tag {
    // BNode* p;  //某二叉树的地址，用指针
    BTree p;
    struct tag* pnext;
} tag_t, *ptag_t;

//////////////////栈
//中序遍历非递归用到
#define MaxSize 50
// typedef BNode ElemType;
typedef BTree ElemType;

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

////////////////////队列
//层次遍历使用
//链队列
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

//判队空
bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//入队
void EnQueue(LinkQueue& Q, ElemType x) {
    //队尾入队
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;

    Q.rear->next = s;
    Q.rear = s;
}
//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //队头出队
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;  // Q.rear前移
    free(p);
    return true;
}