/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 19:16:19
 * @Description: �ڶ�����ϰջ
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//��ʼ��
void InitStack(SqStack& S){
    S.top = -1;
}

//��ջ��
bool StackEmpty(SqStack S){
    if(-1 == S.top)
        return true;
    else   
        return false;
}

///��ջ
bool Push(SqStack& S, ElemType x){
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

//��ջ
bool Pop(SqStack& S, ElemType& x){
    if(-1 == S.top)
        return false;
    x = S.data[S.top--];
    return false;
}

//��ջ��Ԫ��
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
