/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-07-27 20:39:12
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintDList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%5d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//双向链表头插法
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;

    DNode* s;

    int x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        s->next = DL->next;
        if (DL->next)
            DL->next->prior = s;
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }

    return DL;
}

//双向链表尾插法
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

//按序号查找结点
DNode* GetElem(DLinkList DL, int i) {
    DNode* p = DL->next;
    int j = 1;
    if (0 == i)
        return DL;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//将值为e的结点插入到第i个位置
bool DList_Insert(DLinkList& DL, int i, ElemType e) {
    DNode* p = GetElem(DL, i - 1);

    //待插入位置的前一个结点若为NULL
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

//删除第i个结点
bool DList_Del(DLinkList& DL, int i) {
    DNode* p = GetElem(DL, i - 1);
    if (NULL == p)
        return false;

    DNode* q = p->next;
    if (NULL == q)
        return false;

    p->next = q->next;
    if (q->next)
        q->next->prior = p;
    free(q);

    return true;
}

main() {
    DLinkList DL;
    // DList_Head_Insert(DL);
    // PrintDList(DL);

    DList_Tail_Insert(DL);
    PrintDList(DL);

    DNode* p = GetElem(DL, 2);
    printf("%d\n", p->data);

    //插入
    DList_Insert(DL, 2, 100);
    PrintDList(DL);

    //删除
    DList_Del(DL, 2);
    PrintDList(DL);
}
