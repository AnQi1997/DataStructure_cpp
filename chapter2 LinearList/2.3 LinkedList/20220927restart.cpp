/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-09-27 17:53:52
 * @Description: 重启单链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

//头插法
LinkList ListHeadInsert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode* s;
    int x;
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

//尾插法
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

//按序号查找结点
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

//按值查找结点
LNode* LocateElem(LinkList& L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

//将新结点插入第i个位置
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

//删除第i个结点
bool ListDelete(LinkList& L, int i) {
    LNode* p = GetElem(L, i - 1);
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

//打印函数
void PrintList(LinkList L) {
    L = L->next;
    while (L) {
        printf("%6d", L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    LinkList L;

    //头插法
    ListHeadInsert(L);
    printf("头插法建立的单链表:");
    PrintList(L);

    //尾插法
    ListTailInsert(L);
    printf("尾插法建立的单链表:");
    PrintList(L);

    //按序号查找
    LNode* p = GetElem(L, 2);
    printf("单链表第2个元素是：%d\n", p->data);

    //按值查找
    p = LocateElem(L, 10);
    printf("单链表中值为10的元素是：%d\n", p->data);

    //新结点插入第i个位置
    bool flag = ListInsert(L, 2, 100);
    if (flag) {
        printf("新结点值为100，插入后：");
        PrintList(L);
    } else
        printf("插入失败\n");

    //删除第i个位置
    printf("第二个元素删除前的单链表如下：\n");
    PrintList(L);
    flag = ListDelete(L, 2);
    if (flag) {
        printf("第二个位置删除后的单链表如下：\n");
        PrintList(L);
    } else
        printf("删除失败\n");
}
