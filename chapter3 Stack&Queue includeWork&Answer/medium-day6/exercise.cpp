/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-28 12:48:09
 * @Description:
 * 新建一个栈，读取标准输入 3 个整数3 4 5，
 * 入栈 3 4 5，依次出栈，打印 5 4 3，
 * 新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，
 * 入队7时，队满，打印false，然后依次出队，输出 3 4 5 6
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

//栈
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack& S) {
    S.top = -1;
}

//入栈
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

//循环队列
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化
void InitSqQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

//入队
//有关模取问题：便于解决由 最大下标位置 移到到 0 下标时的越界处理。
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
    SqStack S;
    InitStack(S);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);

    ElemType x;
    bool flag;
    flag = Pop(S, x);
    if (flag)
        printf("出栈成功，出栈元素是%d\n", x);
    flag = Pop(S, x);
    if (flag)
        printf("出栈成功，出栈元素是%d\n", x);
    flag = Pop(S, x);
    if (flag)
        printf("出栈成功，出栈元素是%d\n", x);

    SqQueue Q;
    InitSqQueue(Q);
    flag = EnQueue(Q, 3);
    if (flag)
        printf("入队成功\n");

    flag = EnQueue(Q, 4);
    if (flag)
        printf("入队成功\n");

    flag = EnQueue(Q, 5);
    if (flag)
        printf("入队成功\n");

    flag = EnQueue(Q, 6);
    if (flag)
        printf("入队成功\n");

    flag = EnQueue(Q, 7);
    if (flag)
        printf("true\n");
    else
        printf("false\n");

    flag = DeQueue(Q, x);
    if (flag)
        printf("出队元素是：%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队元素是：%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队元素是：%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("出队元素是：%d\n", x);
}
