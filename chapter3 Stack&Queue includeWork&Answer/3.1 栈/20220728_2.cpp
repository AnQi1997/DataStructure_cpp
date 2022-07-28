/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 19:45:56
 * @Description: 第二次练习栈，自己写
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack& S) {
    S.top = -1;
}
//判栈空
bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}
//进栈
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
//读栈顶元素
bool GetTop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

int main() {
    SqStack S;
    InitStack(S);

    if (StackEmpty(S)) {
        printf("栈空\n");
    } else {
        printf("栈不空\n");
    }

    Push(S, 10);
    Push(S, 20);
    Push(S, 30);

    ElemType x;
    GetTop(S, x);
    printf("栈顶元素是：%d\n", x);

    Pop(S, x);
    printf("出栈元素是：%d\n", x);
    Pop(S, x);
    printf("出栈元素是：%d\n", x);
    Pop(S, x);
    printf("出栈元素是：%d\n", x);
}
