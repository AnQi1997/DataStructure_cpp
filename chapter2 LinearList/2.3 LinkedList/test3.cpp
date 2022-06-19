#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    L = L->next;
    while (L) {
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}

//ͷ�巨����������
LinkList List_HeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode* s;
    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        s->next = L->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

//β�巨����������
LinkList List_TailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode* r = L;  //�ζ�ָ��

    LNode* s;  //������Ľ��

    ElemType x;
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

//����Ų���
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    /*
    ү���ˣ����ϣ�
    */
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

//��ֵ����
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;

    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//�½����뵽��i��λ��
bool ListFrontInsert(LinkList L, int i, ElemType e) {
    //�ҵ�����λ��ǰ�ĵ�һ�����
    LNode* p = GetElem(L, i - 1);
    // LNode* q = p->next;

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

int main() {
    LinkList L;

    // List_HeadInsert(L);
    // PrintList(L);

    List_TailInsert(L);
    PrintList(L);

    //����Ų��� �� ���ҵ�i��
    // LNode* p = GetElem(L, 2);
    // printf("%d\n", p->data);

    //��ֵ����
    // LNode* p = LocateElem(L, 6);
    // printf("%d\n", LocateElem(L, 6)->data);

    //����Ԫ�ص���i��λ��
    // bool flag = ListFrontInsert(L, 2, 100);
    // if (flag) {
    //     PrintList(L);
    // } else {
    //     printf("����ʧ��!");
    // }

    //ɾ����i�����
    // bool flag2 = ListDelete(L, 2);
    // if (flag2) {
    //     PrintList(L);
    // } else {
    //     printf("ɾ��ʧ�ܣ�");
    // }
}