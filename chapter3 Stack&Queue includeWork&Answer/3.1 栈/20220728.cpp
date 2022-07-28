/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 19:16:19
 * @Description: 第二次练习栈
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化
void InitStack(SqStack& S){
    S.top = -1;
}

//判栈空
bool StackEmpty(SqStack S){
    if(-1 == S.top)
        return true;
    else   
        return false;
}

///入栈
bool Push(SqStack& S, ElemType x){
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

//出栈
bool Pop(SqStack& S, ElemType& x){
    if(-1 == S.top)
        return false;
    x = S.data[S.top--];
    return false;
}

//读栈顶元素
bool GetTop(SqStack& S, ElemType& x){
    if(-1 == S.top)
        return false;
    x = S.data[S.top];
    return true;
}


int main() {
    SqStack S;
    InitStack(S);

    bool flag = StackEmpty(S);
    printf("%c\n", flag);

}
