/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 20:36:19
 * @Description: 循环队列（自己写）
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
void InitSqQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}
//判空
bool isEmpty(SqQueue& Q) {
    if (Q.rear = Q.front)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return true;
    Q.data[Q.rear + 1] = x;
    Q.rear++;
    return true;
}
//出队
bool DeQueue(SqQueue& Q, ElemType& x) {
    //如果队空 返回false
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front--;
    return true;
}

int main() {
    SqQueue Q;
    InitSqQueue(Q);

    if (isEmpty(Q))
        printf("循环队列空\n");
    else
        printf("循环队列不空\n");

    bool flag;
    flag = (Q, 10);
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
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
    DeQueue(Q, x);
    printf("出队元素是：%d\n", x);
}
