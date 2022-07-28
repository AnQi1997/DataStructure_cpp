/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-28 20:36:19
 * @Description: ѭ�����У��Լ�д��
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
void InitSqQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}
//�п�
bool isEmpty(SqQueue& Q) {
    if (Q.rear = Q.front)
        return true;
    else
        return false;
}
//���
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return true;
    Q.data[Q.rear + 1] = x;
    Q.rear++;
    return true;
}
//����
bool DeQueue(SqQueue& Q, ElemType& x) {
    //����ӿ� ����false
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front--;
    return true;
}

int main() {
    SqQueue Q;
    InitSqQueue(Q);

    if (isEmpty(Q))
        printf("ѭ�����п�\n");
    else
        printf("ѭ�����в���\n");

    bool flag;
    flag = (Q, 10);
    if (flag)
        printf("��ӳɹ�\n");
    EnQueue(Q, 20);
    if (flag)
        printf("��ӳɹ�\n");
    EnQueue(Q, 30);
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
