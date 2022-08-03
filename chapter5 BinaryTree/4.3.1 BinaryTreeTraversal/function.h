/*
 * @Author: 2361067080@qq.com
 * @Date: 2021-10-22 10:46:09
 * @Description: 
 */
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode {
    BiElemType c;  // c�����鼮�ϵ�data
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

//���нṹ
typedef struct tag {
    BiTree p;  //����ĳһ�����ĵ�ֵַ
    struct tag* pnext;
} tag_t, *ptag_t;

//ջ��������ݽṹ
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

//���е�������ݽṹ
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
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));  //ͷ��βָ��ͬһ�����
    Q.front->next = NULL;                                    //ͷ����nextָ��ΪNULL
}

bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//��ӣ�β�����뷨
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;  // rearʼ��ָ��β��
    Q.rear = s;
}

//����  ͷ��ɾ����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;             //����Ϊ��
    
    LinkNode* p = Q.front->next;  //ͷ���ʲô��û�棬����ͷ������һ���ڵ��������
    x = p->data;
    
    Q.front->next = p->next;  //����
    if (Q.rear == p)          //ɾ���������һ��Ԫ��
        Q.rear = Q.front;     //������Ϊ��
    free(p);
    return true;
}