/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-29 15:09:44
 * @Description: �����У�����
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *rear, *front;
} LinkQueue;

//��ʼ��
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
//�жӿ�
bool IsEmpty(LinkQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//���
//�õ������ʾ����ʽ�����ر��ʺ�������Ԫ�ر䶯�Ƚϴ�����Σ�
//���Ҳ����ڶ������Ҳ������������
bool EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;

    Q.rear = s;
    return true;
}

//����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //���ӿգ�����false
    if (Q.rear == Q.front)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;

    if (Q.rear == p)  //���ֻ��һ�����
        Q.front = Q.rear;
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool flag;

    InitQueue(Q);

    if (IsEmpty(Q))
        printf("�ӿ�\n");
    else
        printf("�Ӳ���\n");

    //����
    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);

    //����
    ElemType x;

    flag = DeQueue(Q, x);
    printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
    if (flag)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
    flag = DeQueue(Q, x);
    if (flag)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
}
