/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 09:33:09
 * @Description: 栈的数组实现，自己写
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化栈
void InitStack(SqStack& S) {
    S.top = -1;  //代表栈空
}

//判断栈空
bool StackEmpty(SqStack& S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

//入栈
bool Push(SqStack& S, ElemType x) {
    //栈满，停止进栈
    if (MaxSize - 1 == S.top)
        return false;
    //栈空，++S.top
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

//读取栈顶元素
bool GetTop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}

main() {
    SqStack S;
    ElemType x;
    bool flag;

    InitStack(S);
    flag = StackEmpty(S);
    if (flag) {
        printf("栈空\n");
    }

    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);

    flag = GetTop(S, x);
    if (flag) {
        printf("栈顶元素是：%d\n", x);
    }

    flag = Pop(S, x);
    if(flag){
        printf("出栈元素是%d\n", x);
    }

    flag = Pop(S, x);
    if(flag){
        printf("出栈元素是%d\n", x);
    }
}
