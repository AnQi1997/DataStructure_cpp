/*
 * @Author: 2361067080@qq.com
 * @Date: 2022-06-27 18:23:14
 * @Description: 中级-day5
 * 输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，
 * 查找第二个位置的值并输出，
 * 在2个位置插入99，输出为  3 99  4  5  6  7，
 * 删除第4个位置的值，打印输出为  3 99  4  5  6  7。
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
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

//尾插法建立单链表
LinkList List_Tail_Insert(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *s, *r = L;

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

//查找第i个位置
LNode* GetElem(LinkList L, int i) {
    if (0 == i)
        return L;
    if (i < 1)
        return NULL;
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//在第i个位置插入一个值
bool List_Insert_i_x(LinkList L, ElemType& x, int i) {
    //获得i-1个位置
    LNode* p = GetElem(L, i);
    if(NULL == p)
        return false;

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = x;

    s->next = p->next;
    p->next = s;

    return true;
}

//删除第i个位置的元素
bool ListDelete(LinkList L, int i){

}

int main() {
    LinkList L;
    List_Tail_Insert(L);
    PrintList(L);

    LNode* p = GetElem(L, 2);
    printf("%d\n", p->data);
}
