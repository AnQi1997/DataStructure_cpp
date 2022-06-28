/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-28 09:41:30
 * @Description: ѭ�����У��ڶ���
 * ��ʼ��
 * �жӿ�
 * ���
 * ����
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

// C++�����ã���ָ��Q�ĵ�ַ���뺯��
void InitQueue(SqQueue& Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//����
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//����
bool DeQueue(SqQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main() {
    SqQueue Q;

    InitQueue(Q);

    bool flag = isEmpty(Q);
    if (flag)
        printf("�ӿ�\n");

    flag = EnQueue(Q, 10);
    if (flag)
        printf("���ӳɹ�\n");
    flag = EnQueue(Q, 20);
    if (flag)
        printf("���ӳɹ�\n");
    flag = EnQueue(Q, 30);
    if (flag)
        printf("���ӳɹ�\n");

    ElemType x;
    flag = DeQueue(Q, x);
    if (flag)
        printf("���ӳɹ�������Ԫ����%d\n", x);

    flag = DeQueue(Q, x);
    if (flag)
        printf("���ӳɹ�������Ԫ����%d\n", x);

    flag = DeQueue(Q, x);
    if (flag)
        printf("���ӳɹ�������Ԫ����%d\n", x);
}
