/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 19:45:56
 * @Description: �ڶ�����ϰջ���Լ�д
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;
}
//��ջ��
bool StackEmpty(SqStack S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}
//��ջ
bool Push(SqStack& S, ElemType x) {
    if (MaxSize - 1 == S.top)
        return false;
    S.data[++S.top] = x;
    return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    return true;
}
//��ջ��Ԫ��
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
        printf("ջ��\n");
    } else {
        printf("ջ����\n");
    }

    Push(S, 10);
    Push(S, 20);
    Push(S, 30);

    ElemType x;
    GetTop(S, x);
    printf("ջ��Ԫ���ǣ�%d\n", x);

    Pop(S, x);
    printf("��ջԪ���ǣ�%d\n", x);
    Pop(S, x);
    printf("��ջԪ���ǣ�%d\n", x);
    Pop(S, x);
    printf("��ջԪ���ǣ�%d\n", x);
}
