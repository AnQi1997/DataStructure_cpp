/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-05-15 17:42:43
 * @Description:
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];  //����
    int top;
} SqStack;

void InitStack(SqStack& S) {
    S.top = -1;  //����ջΪ��
}

//��ջ
bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1)  //����Ĵ�С���ܸı䣬�������Խ��
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x) {
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];  //�������x=S.data[S.top];S.top=S.top-1;
    return true;
}

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  //����,�洢MaxSize-1��Ԫ��
    int front, rear;         //����ͷ ����β
} SqQueue;

void InitQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

//���
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)  //�ж��Ƿ����
        return false;
    Q.data[Q.rear] = x;  // 3 4 5 6
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//����
bool DeQueue(SqQueue& Q, ElemType& x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];  //�Ƚ��ȳ�
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main() {
    SqStack S;  //�Ƚ���� FILO  LIFO
    bool flag;
    ElemType m;    //��������ó���Ԫ��
    InitStack(S);  //��ʼ��
    int i, num;
    for (i = 0; i < 3; i++) {
        scanf("%d", &num);
        Push(S, num);
    }
    for (i = 0; i < 3; i++) {
        Pop(S, m);
        printf("%2d", m);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    for (i = 0; i < 5; i++)  //���5��Ԫ�أ����һ��Ԫ�ز�����ӳɹ�
    {
        scanf("%d", &num);
        flag = EnQueue(Q, num);
        if (false == flag) {
            printf("false\n");
        }
    }
    ElemType element;
    for (i = 0; i < 4; i++)  //����4��Ԫ�ز���ӡÿһ��
    {
        DeQueue(Q, element);
        printf("%2d", element);
    }
    printf("\n");
}