/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-29 15:09:44
 * @Description: 链队列（抄）
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *rear, *front;
} LinkQueue;

//初始化
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
//判队空
bool IsEmpty(LinkQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//入队
//用单链表表示的链式队列特别适合于数据元素变动比较大的情形，
//而且不存在队列满且产生溢出的问题
bool EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;

    Q.rear = s;
    return true;
}

//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //若队空，返回false
    if (Q.rear == Q.front)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;

    if (Q.rear == p)  //如果只有一个结点
        Q.front = Q.rear;
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool flag;

    InitQueue(Q);

    if (IsEmpty(Q))
        printf("队空\n");
    else
        printf("队不空\n");

    //进队
    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);

    //出队
    ElemType x;

    flag = DeQueue(Q, x);
    printf("出队成功，出队元素是：%d\n", x);
    if (flag)
        printf("出队成功，出队元素是：%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队成功，出队元素是：%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队成功，出队元素是：%d\n", x);
}
