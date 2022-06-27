/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-26 23:28:43
 * @Description: ���е���ʽ�洢
 * ��ʼ������
 * �жӿ�
 * ���
 * ����
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//��ʽ���н��
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

//��ʽ����
typedef struct {
    //����ͷָ���βָ��
    LinkNode *front, *rear;
} LinkQueue;

//��ʼ��
void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//�ж϶��п�
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//��ӣ�β�巨
void EnQueue(LinkQueue& Q, ElemType x) {
    //����ռ�
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;

    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

//���ӣ�ͷ��ɾ����
bool DeQueue(LinkQueue& Q, ElemType& x) {
    //�ӿ�
    if (Q.rear == Q.front)
        return false;

    LinkNode* p = Q.front->next;
    x = p->data;

    Q.front->next = p->next;

    //���ɾ���������һ��Ԫ��
    if (Q.rear == p) {
        Q.rear = Q.front;
    }

    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    bool ret;
    ElemType x;

    InitQueue(Q);

    ret = IsEmpty(Q);

    if (ret)
        printf("�ӿ�\n");
    else
        printf("�Ӳ���\n");

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);

    ret = DeQueue(Q, x);
    if(ret)
        printf("���ӳɹ�������Ԫ��ֵΪ��%d\n", x);
    else   
        printf("����ʧ��");
}
