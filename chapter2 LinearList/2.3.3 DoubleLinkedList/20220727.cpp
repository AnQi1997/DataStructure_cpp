/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-27 19:18:06
 * @Description: �ڶ�����ϰ˫������
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintDLinkList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//˫������ͷ�巨
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;
    DL->next = NULL;

    DNode* s;
    int x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        s->next = DL->next;
        if (DL->next)  //ֻ��һ��ͷ���ʱ����ִ����һ��
            DL->next->prior = s;
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//˫������β�巨
DLinkList DList_Tail_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;

    DNode *s, *r = DL;
    int x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        r->next = s;
        s->prior = r;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return DL;
}

//����Ų��ҽ��ֵ�����ҵ�i�����
DNode* GetElem(DLinkList DL, int i) {
    int j = 1;
    if (i == 0)
        return DL;
    if (i < 1)
        return NULL;

    DNode* p = DL->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//���½ڵ���뵽��i��λ�ã�������ֵΪe
bool DListInsert(DLinkList& DL, int i, ElemType e) {
    DNode* p = GetElem(DL, i - 1);

    if (p == NULL)
        return false;
        
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//ɾ����i�����
bool ListDelete(DLinkList& DL, int i) {
    DNode* p = GetElem(DL, i - 1);

    if (NULL == p)
        return false;

    DNode* q = p->next;
    if (NULL == q)
        return false;

    p->next = q->next;
    //���ɾ���Ĳ���β��㣬��ִ����һ��
    if (q->next)
        q->next->prior = p;

    free(q);
    return true;
}

int main() {
    DLinkList DL;
    // DList_Head_Insert(DL);
    // PrintDLinkList(DL);

    DList_Tail_Insert(DL);
    PrintDLinkList(DL);

    // DNode* p = GetElem(DL, 2);
    // printf("%d\n", p->data);

    DListInsert(DL, 2, 100);
    PrintDLinkList(DL);
}
