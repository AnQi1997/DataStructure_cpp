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
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    
}
































