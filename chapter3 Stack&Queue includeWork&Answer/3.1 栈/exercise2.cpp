/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 09:33:09
 * @Description: ջ������ʵ�֣��Լ�д
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//��ʼ��ջ
void InitStack(SqStack& S) {
    S.top = -1;  //����ջ��
}

//�ж�ջ��
bool StackEmpty(SqStack& S) {
    if (-1 == S.top)
        return true;
    else
        return false;
}

//��ջ
bool Push(SqStack& S, ElemType x) {
    //ջ����ֹͣ��ջ
    if (MaxSize - 1 == S.top)
        return false;
    //ջ�գ�++S.top
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

//��ȡջ��Ԫ��
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
        printf("ջ��\n");
    }

    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);

    flag = GetTop(S, x);
    if (flag) {
        printf("ջ��Ԫ���ǣ�%d\n", x);
    }

    flag = Pop(S, x);
    if(flag){
        printf("��ջԪ����%d\n", x);
    }

    flag = Pop(S, x);
    if(flag){
        printf("��ջԪ����%d\n", x);
    }
}
