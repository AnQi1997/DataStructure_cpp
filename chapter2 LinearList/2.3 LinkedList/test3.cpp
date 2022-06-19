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

//头插法建立单链表
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

//尾插法建立单链表
LinkList List_TailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode* r = L;  //游动指针

    LNode* s;  //待插入的结点

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

//按序号查找
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    /*
    爷忘了，补上！
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

//按值查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;

    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//新结点插入到第i个位置
bool ListFrontInsert(LinkList L, int i, ElemType e) {
    //找到插入位置前的第一个结点
    LNode* p = GetElem(L, i - 1);
    // LNode* q = p->next;

    LNode* s = (LNode*)malloc(sizeof(LNode));

    s->data = e;

    s->next = p->next;
    p->next = s;

    return true;
}

//删除第i个结点
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

    //按序号查找 ： 查找第i个
    // LNode* p = GetElem(L, 2);
    // printf("%d\n", p->data);

    //按值查找
    // LNode* p = LocateElem(L, 6);
    // printf("%d\n", LocateElem(L, 6)->data);

    //插入元素到第i个位置
    // bool flag = ListFrontInsert(L, 2, 100);
    // if (flag) {
    //     PrintList(L);
    // } else {
    //     printf("插入失败!");
    // }

    //删除第i个结点
    // bool flag2 = ListDelete(L, 2);
    // if (flag2) {
    //     PrintList(L);
    // } else {
    //     printf("删除失败！");
    // }
}