/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-29 16:07:17
 * @Description: �����У��Լ�д��
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;          //������
    struct LinkNode* next;  //ָ����
} LinkNode;

typedef struct {
    LinkNode *front, *rear;  //��ͷ ��β
} LinkQueue;

//��ʼ��
void InitLinkQueue(LinkQueue& Q) {
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
bool EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    //��β����
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;

    return true;
}

//����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)  //�ӿգ�����false
        return false;

    //�Ӷ�ͷ��ʼ����
    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;
    if (Q.rear == p)
        Q.front = Q.rear;
    free(p);

    return true;
}

int main() {
    LinkQueue Q;
    //��ʼ��
    InitLinkQueue(Q);

    //�жӿ�
    if (IsEmpty(Q))
        printf("���ӿ�\n");
    else
        printf("���Ӳ���\n");

    //���
    bool flag;

    flag = EnQueue(Q, 10);
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

    flag = DeQueue(Q, x);
    printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);

    DeQueue(Q, x);
    printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);

    DeQueue(Q, x);
    printf("���ӳɹ�������Ԫ���ǣ�%d\n", x);
}
