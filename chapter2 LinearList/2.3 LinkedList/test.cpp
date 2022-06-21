#include <stdio.h>
#include <stdlib.h>
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！
// TODO 纯纯的抄！！！

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

// LNode 和 *LinkList 是不同名字的同一指针类型
//命名不同是为了概念上更加明确
//*LinkList类型的指针变量表示它是一个单链表  结构体指针类型起别名
// LNode类型的指针变量表示它是指向某一结点的指针  给结构体类型起别名
//指针用箭头访问成员   访问结构体变量用点  别问，问就是规定，记住就这样用
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

        s->next = L->next;
        L->next = s;

        scanf("%d", &x);
    }
    return L;
}

/**
 * @brief 头插法
 *
 * @param L
 * @return LinkList
 */
LinkList List_HeadInsert(LinkList& L) {
    LNode* s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
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

LinkList List_RearInsert(LinkList& L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
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

// 按序号查找
// 从第一个结点出发，直到找到第i个结点为止，
// 否则返回最后一个结点指针域NULL
LNode* GetElem(LinkList L, int i) {
    int j = 1;           //计数器
    LNode* p = L->next;  //指向首节点

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

/**
 * @brief 按值查找
 * 从单链表第一个结点开始，
 * 从前到后依次比较各结点数据域的值，
 * 若等于给定值e，则返回该结点的指针
 * 若整个单链表没有这样的结点，则返回NULL
 */
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

/**
 * @brief 新结点插入第i个位置
 * 将值为x的新结点插入到单链表第i个位置上，
 * 先检查插入位置的合法性，
 * 然后找到插入位置的前驱结点，即第i-1个结点，在其后插入新结点
 */
bool ListFrontInsert(LinkList L, int i, ElemType e) {
    LinkList p = GetElem(L, i - 1);
    if (NULL == p)  
    //放的这个位置不存在 也就是插入位置在头结点之前的时候
    //也就是插入位置不合法，i=0时，插入的位置是头结点，返回false
        return false;
    //此时找到插入位置

    //为插入元素申请空间
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next;
    p->next = s;
    return true;
}

//删除第i个结点
bool ListDelete(LinkList L, int i) {
    LNode* p = GetElem(L, i - 1);
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    LinkList L;

    // CreatList1(L);
    // printList(L);

    // CreatList2(L);
    // printList(L);

    // List_HeadInsert(L);
    // printList(L);

    //按序号查找
    // GetElem(L, 1);
    // printf("%d", GetElem(L, 1)->data);

    //按值查找
    // LNode* p = LocateElem(L, 2);
    // printf("%d", p->data);

    List_RearInsert(L);
    printList(L);

    bool flag = ListFrontInsert(L, 0, 100);
    if (flag) {
        printList(L);
    } else {
        printf("插入失败！");
    }

    // ListDelete(L, 1);
    // printList(L);
}