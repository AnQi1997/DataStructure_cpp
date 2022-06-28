/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-28 12:48:09
 * @Description:
 * �½�һ��ջ����ȡ��׼���� 3 ������3 4 5��
 * ��ջ 3 4 5�����γ�ջ����ӡ 5 4 3��
 * �½�ѭ�����У�MaxsizeΪ5������ȡ��׼����3 4 5 6 7��
 * ���7ʱ����������ӡfalse��Ȼ�����γ��ӣ���� 3 4 5 6
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

//ջ
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;
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

//ѭ������
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//��ʼ��
void InitSqQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

//���
//�й�ģȡ���⣺���ڽ���� ����±�λ�� �Ƶ��� 0 �±�ʱ��Խ�紦��
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//����
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
        printf("��ջ�ɹ�����ջԪ����%d\n", x);
    flag = Pop(S, x);
    if (flag)
        printf("��ջ�ɹ�����ջԪ����%d\n", x);
    flag = Pop(S, x);
    if (flag)
        printf("��ջ�ɹ�����ջԪ����%d\n", x);

    SqQueue Q;
    InitSqQueue(Q);
    flag = EnQueue(Q, 3);
    if (flag)
        printf("��ӳɹ�\n");

    flag = EnQueue(Q, 4);
    if (flag)
        printf("��ӳɹ�\n");

    flag = EnQueue(Q, 5);
    if (flag)
        printf("��ӳɹ�\n");

    flag = EnQueue(Q, 6);
    if (flag)
        printf("��ӳɹ�\n");

    flag = EnQueue(Q, 7);
    if (flag)
        printf("true\n");
    else
        printf("false\n");

    flag = DeQueue(Q, x);
    if (flag)
        printf("����Ԫ���ǣ�%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("����Ԫ���ǣ�%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("����Ԫ���ǣ�%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("����Ԫ���ǣ�%d\n", x);
}
