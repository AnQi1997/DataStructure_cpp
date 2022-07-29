/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-29 16:07:17
 * @Description: 链队列（自己写）
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;          //数据域
    struct LinkNode* next;  //指针域
} LinkNode;

typedef struct {
    LinkNode *front, *rear;  //队头 队尾
} LinkQueue;

//初始化
void InitLinkQueue(LinkQueue& Q) {
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
bool EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    //队尾插入
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;

    return true;
}

//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)  //队空，返回false
        return false;

    //从队头开始出队
    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (Q.rear == p)
        Q.front = Q.rear;
    free(p);

    return true;
}

int main() {
    LinkQueue Q;
    //初始化
    InitLinkQueue(Q);

    //判队空
    if (IsEmpty(Q))
        printf("链队空\n");
    else
        printf("链队不空\n");

    //入队
    bool flag;

    flag = EnQueue(Q, 10);
    if (flag)
        printf("入队成功\n");
    EnQueue(Q, 20);
    if (flag)
        printf("入队成功\n");
    EnQueue(Q, 30);
    if (flag)
        printf("入队成功\n");

    //出队
    ElemType x;

    flag = DeQueue(Q, x);
    printf("出队成功，出队元素是：%d\n", x);

    DeQueue(Q, x);
    printf("出队成功，出队元素是：%d\n", x);

    DeQueue(Q, x);
    printf("出队成功，出队元素是：%d\n", x);
}
