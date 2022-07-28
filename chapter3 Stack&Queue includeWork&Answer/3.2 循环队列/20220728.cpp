/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 20:14:14
 * @Description: 第二次练习循环队列(抄)
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化
void InitQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

//判空
bool isEmpty(SqQueue& Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue& Q, ElemType& x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main() {
    SqQueue Q;

    InitQueue(Q);

    bool flag;

    flag = isEmpty(Q);
    if (flag)
        printf("队空\n");
    else
        printf("队不空\n");

    //入队
    flag = EnQueue(Q, 10);
    if (flag)
        printf("入队成功\n");
    flag = EnQueue(Q, 20);
    if (flag)
        printf("入队成功\n");
    flag = EnQueue(Q, 30);
    if (flag)
        printf("入队成功\n");

    //出队
    ElemType x;
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
}