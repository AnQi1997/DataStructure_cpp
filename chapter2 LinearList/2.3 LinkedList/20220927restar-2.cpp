/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-09-27 19:07:29
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

//ͷ�巨
LinkList ListHeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    int x;
    scanf("%d", &x);
    LNode* s;

    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        s->next = L->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

//β�巨
LinkList ListTailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;

    int x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        r->next = s;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//����Ų��ҽ��
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;

    if (i == 0)
        return L;
    if (i < 0)
        return NULL;

    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//��ֵ���ҽ��
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;

    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//�ڵ�i��λ�ò����½��
bool ListInsert(LinkList& L, int i, ElemType e) {
    LNode* p = GetElem(L, i - 1);

    if (NULL == p)
        return false;

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next;
    p->next = s;

    return true;
}

//ɾ����i�����
bool ListDelete(LinkList& L, int i) {
    LNode* p = GetElem(L, i - 1);
    LNode* q = p->next;

    p->next = q->next;
    free(q);

    return true;
}


//TODO
int CountNum(LinkList L) {
    int count = 0;
    if (L == NULL){
        L = L->next;
        return 0;
    }
    while (L->data) {
        count++;
        L = L->next;
    }
    return count;
}

void PrintList(LinkList L) {
    L = L->next;
    while (L) {
        printf("%6d", L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    LinkList L;

    ListHeadInsert(L);
    printf("ͷ�巨�����ĵ�������\n");
    PrintList(L);

    int num = CountNum(L);
    printf("%d\n", num);

    // ListTailInsert(L);
    // printf("β�巨�����ĵ�������\n");
    // PrintList(L);

    // //����Ų���
    // LNode* p = GetElem(L, 2);
    // printf("��������2��Ԫ���ǣ�%d\n", p->data);

    // //��ֵ����
    // p = LocateElem(L, 10);
    // printf("��������ֵΪ10��Ԫ���ǣ�%d\n", p->data);

    // //�½������i��λ��
    // bool flag = ListInsert(L, 2, 100);
    // if (flag) {
    //     printf("�½��ֵΪ100�������");
    //     PrintList(L);
    // } else
    //     printf("����ʧ��\n");

    // //ɾ����i��λ��
    // printf("�ڶ���Ԫ��ɾ��ǰ�ĵ��������£�\n");
    // PrintList(L);
    // flag = ListDelete(L, 2);
    // if (flag) {
    //     printf("�ڶ���λ��ɾ����ĵ��������£�\n");
    //     PrintList(L);
    // } else
    //     printf("ɾ��ʧ��\n");
}