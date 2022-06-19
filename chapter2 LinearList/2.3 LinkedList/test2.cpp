#include <stdio.h>
#include <stdlib.h>
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写
// TODO 爷自己写滴，自己手写

typedef int ElemType;  //起别名

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    //带头结点，头结点里啥也没有，后移一个
    L = L->next;
    while (L != NULL) {
        printf("%6d", L->data);
        L = L->next;
    }
    printf("\n");
}

/**
 * @brief 头插法
 *
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
 * @brief 尾插法
 * 需要一个尾指针
 */
LinkList List_TailInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

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

/**
 * @brief
 * 按序号查找
 * 从第一个结点出发，直到找到第i个结点为止，
 * 否则返回最后一个结点指针域NULL
 */
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    //定义搜寻指针
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

/**
 * @brief 按值查找
 *
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
    //查找到第i-1个位置
    LNode* p = GetElem(L, i - 1);
    // p是第i-1个结点
    //申请新结点s
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

/**
 * @brief
 *
 * @return int
 */
int main() {
    LinkList L;

    //头插法：逆序插入
    List_HeadInsert(L);
    PrintList(L);

    // bool flag = ListFrontInsert(L, 2, 100);
    // if (flag) {
    //     PrintList(L);
    // } else {
    //     printf("插入失败");
    // }
    //尾插法：顺序插入 插入顺序即前后顺序
    // List_TailInsert(L);
    // PrintList(L);
    //按序号查找
    // printf("%d\n", GetElem(L, 2)->data);
    // 按值查找
    // printf("%d\n", LocateElem(L, 2)->data);

    ListDelete(L, 2);
    PrintList(L);

    return 0;
}
