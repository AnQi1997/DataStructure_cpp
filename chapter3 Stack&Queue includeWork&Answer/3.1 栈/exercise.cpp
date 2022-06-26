/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 08:50:14
 * @Description: ջ��ʹ������ʵ��
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

//��ջ
bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    //ջ��ָ���ȼ��ٸ�ֵ
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
    bool flag;
    ElemType x;

    InitStack(S);
    flag = StackEmpty(S);
    if(flag){
        printf("ջ��");
    }else{
        printf("ջ����");
    }

    Push(S,1);
    Push(S,2);
    Push(S,3);
    Push(S,4);
    Push(S,5);

    flag = GetTop(S, x);
    if(flag) {
        printf("ջ��Ԫ����%d\n", x);
    }

    //��ջ
    flag = Pop(S, x);
    if(flag){
        printf("��ջ��ջ��Ԫ��%d", x);
    }

}
