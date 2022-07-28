/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 20:14:14
 * @Description: �ڶ�����ϰѭ������(��)
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//��ʼ��
void InitQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}

//�п�
bool isEmpty(SqQueue& Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//���
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
    SqQueue Q;

    InitQueue(Q);

    bool flag;

    flag = isEmpty(Q);
    if (flag)
        printf("�ӿ�\n");
    else
        printf("�Ӳ���\n");

    //���
    flag = EnQueue(Q, 10);
    if (flag)
        printf("��ӳɹ�\n");
    flag = EnQueue(Q, 20);
    if (flag)
        printf("��ӳɹ�\n");
    flag = EnQueue(Q, 30);
    if (flag)
        printf("��ӳɹ�\n");

    //����
    ElemType x;
    DeQueue(Q, x);
    printf("����Ԫ���ǣ�%d\n", x);
    DeQueue(Q, x);
    printf("����Ԫ���ǣ�%d\n", x);
    DeQueue(Q, x);
    printf("����Ԫ���ǣ�%d\n", x);
}