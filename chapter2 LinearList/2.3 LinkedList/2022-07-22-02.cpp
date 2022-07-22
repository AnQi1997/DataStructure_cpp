/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-22 18:28:32
 * @Description: ��������ϰ2
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;  //������

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    L = L->next;
    while (L) {
        printf("%5d", L->data);
        L = L->next;
    }
    printf("\n");
}

//ͷ�巨
LinkList ListHeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    int x;
    LNode* s;

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

//����Ų���
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

//��ֵ����
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

//�����i��λ��
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

int main() {
    LinkList L;

    // ListHeadInsert(L);
    // PrintList(L);

    ListTailInsert(L);
    PrintList(L);

    // LNode* p = LocateElem(L, 6);
    // printf("%d\n", p->data);

    ListInsert(L, 2, 100);
    PrintList(L);

    ListDelete(L, 2);
    PrintList(L);

}
