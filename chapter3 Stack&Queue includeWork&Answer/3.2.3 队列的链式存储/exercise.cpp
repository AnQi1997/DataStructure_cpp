/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 23:28:43
 * @Description: 队列的链式存储
 * 初始化队列
 * 判队空
 * 入队
 * 出队
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//链式队列结点
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

//链式队列
typedef struct {
    //链表头指针和尾指针
    LinkNode *front, *rear;
} LinkQueue;

//初始化
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断队列空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//入队，尾插法
void EnQueue(LinkQueue& Q, ElemType x) {
    //申请空间
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

//出队，头部删除法
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //队空
    if (Q.rear == Q.front)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;

    //如果删除的是最后一个元素
    if (Q.rear == p) {
        Q.rear = Q.front;
    }

    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool ret;
    ElemType x;

    InitQueue(Q);

    ret = IsEmpty(Q);

    if (ret)
        printf("队空\n");
    else
        printf("队不空\n");

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);

    ret = DeQueue(Q, x);
    if(ret)
        printf("出队成功，出队元素值为：%d\n", x);
    else   
        printf("出队失败");
}
