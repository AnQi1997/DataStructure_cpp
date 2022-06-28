/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-28 09:41:30
 * @Description: 循环队列，第二遍
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

// C++的引用，将指针Q的地址传入函数
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//进队
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main() {
    SqQueue Q;

    InitQueue(Q);

    bool flag = isEmpty(Q);
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
