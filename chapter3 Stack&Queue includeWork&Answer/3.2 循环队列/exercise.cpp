/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-28 08:57:27
 * @Description: 循环队列
 * 初始化
 * 判队空
 * 入队
 * 出队
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

//判队空
bool IsEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        //队空相等，不需为0
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue& Q, ElemType x) {
    //队满
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    //入队
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue& Q, ElemType& x) {
    //队空
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
    flag = IsEmpty(Q);
    if (flag)
        printf("队空\n");

    flag = EnQueue(Q, 10);
    if (flag)
        printf("进队成功\n");

    flag = EnQueue(Q, 20);
    if (flag)
        printf("进队成功\n");

    flag = EnQueue(Q, 30);
    if (flag)
        printf("进队成功\n");

    ElemType x;
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队成功，出队元素是%d\n", x);

    flag = DeQueue(Q, x);
    if (flag)
        printf("出队成功，出队元素是%d\n", x);

    flag = DeQueue(Q, x);
    if (flag)
        printf("出队成功，出队元素是%d\n", x);
}
