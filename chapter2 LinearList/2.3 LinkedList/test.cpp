#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;
// LNode 和 *LinkList 是不同名字的同一指针类型
//命名不同是为了概念上更加明确
//*LinkList类型的指针变量表示它是一个单链表
// LNode类型的指针变量表示它是指向某一结点的指针

void printList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}

/**
 * @brief 头插法建立单链表
 *  该方法从一个空表开始，生成新结点，并将读取到的数据存放到新结点的数据域中
 *  然后将新结点插入到当前链表的表头，即头节点之后
 */
LinkList CreatList1(LinkList& L) {
    LNode* s;  //新结点
    int x;     //新结点数据域

    L = (LinkList)malloc(sizeof(LNode));  //链表头结点
    L->next = NULL;

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;

        s->next = L   456e->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

/**
 * @brief 尾插法建立单链表
 *
 */
LinkList CreatList2(LinkList& L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));

    LNode *s, *r = L;

    scanf("%d", &x);
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(LinkList));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

/**
 * @brief Get the Elem object
 *
 * @param L
 * @param i
 * @return LNode*
 */
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * @brief 按值查找
 *
 * @param L
 * @param e
 * @return LNode*
 */
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

int main() {
    LinkList L;

    // CreatList1(L);
    // printList(L);

    // CreatList2(L);
    // printList(L);
}