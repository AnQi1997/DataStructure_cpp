/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 08:50:14
 * @Description: 栈，使用数组实现
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack& S) {
    S.top = -1;
}

bool StackEmpty(SqStack& S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

//入栈
bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    //栈顶指针先加再赋值
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
    bool flag;
    ElemType x;

    InitStack(S);
    flag = StackEmpty(S);
    if(flag){
        printf("栈空");
    }else{
        printf("栈不空");
    }

    Push(S,1);
    Push(S,2);
    Push(S,3);
    Push(S,4);
    Push(S,5);

    flag = GetTop(S, x);
    if(flag) {
        printf("栈顶元素是%d\n", x);
    }

    //出栈
    flag = Pop(S, x);
    if(flag){
        printf("出栈的栈顶元素%d", x);
    }

}
