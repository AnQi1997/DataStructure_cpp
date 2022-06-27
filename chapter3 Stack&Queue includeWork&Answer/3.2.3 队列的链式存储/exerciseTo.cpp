/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 15:10:30
 * @Description: ������
 * ��ʼ��
 * �жӿ�
 * ���
 * ����
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//���ṹ
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

//�����нṹ
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.rear->next = NULL;
}

//�жӿ�
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//β�巨���
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

//ͷ�巨�� ����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (p == Q.rear)
        Q.front = Q.rear;
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool ret;

    InitQueue(Q);

    //�жӿ�
    ret = IsEmpty(Q);
    if (ret)
        printf("�ӿ�\n");
    else
        printf("�Ӳ���\n");

    //���
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    //����
    ElemType x;
    ret = DeQueue(Q, x);
    if (ret)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);

    ret = DeQueue(Q, x);
    if (ret)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);

    ret = DeQueue(Q, x);
    if (ret)
        printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
}
