/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 15:10:30
 * @Description: 链队列
 * 初始化
 * 判队空
 * 入队
 * 出队
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//结点结构
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

//链队列结构
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.rear->next = NULL;
}

//判队空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//尾插法入队
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

//头插法， 出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (p == Q.rear)
        Q.front = Q.rear;
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool ret;

    InitQueue(Q);

    //判队空
    ret = IsEmpty(Q);
    if (ret)
        printf("队空\n");
    else
        printf("队不空\n");

    //入队
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    //出队
    ElemType x;
    ret = DeQueue(Q, x);
    if (ret)
        printf("出队成功，出队元素是：%d\n", x);

    ret = DeQueue(Q, x);
    if (ret)
        printf("出队成功，出队元素是：%d\n", x);

    ret = DeQueue(Q, x);
    if (ret)
        printf("出队成功，出队元素是：%d\n", x);
}
