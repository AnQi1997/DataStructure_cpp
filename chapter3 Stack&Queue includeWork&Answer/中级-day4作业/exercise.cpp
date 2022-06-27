/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 15:55:22
 * @Description:
 */
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
        printf("%d", L->data);
        L = L->next;
        if (L)
            printf(" ");
    }
    printf("\n");
}

//头插法建立单链表
LinkList List_Head_Insert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    ElemType x;
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

//尾插法建立单链表
LinkList List_Tail_Insert(LinkList& L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* r = L;

    LNode* s;
    ElemType x;
    scanf("%d", &x);

    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        // s->next = r->next;
        r->next = s;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

int main() {
    LinkList L;

    List_Head_Insert(L);
    PrintList(L);

    List_Tail_Insert(L);
    PrintList(L);

}
