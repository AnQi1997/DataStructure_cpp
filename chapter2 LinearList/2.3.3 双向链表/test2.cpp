#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintList(DLinkList DL) {
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//头插法建立双向链表
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;

    DNode* s;

    ElemType x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        s->next = DL->next;
        if (DL->next) {
            //不是只有头结点时
            DL->next->prior = s;
        }
        s->prior = DL;
        DL->next = s;

        scanf("%d", &x);
    }
    return DL;
}

//尾插法建立单链表
DLinkList DList_Tail_Insert(DLinkList& DL) {
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;

    DNode* r = DL;
    DNode* s;

    ElemType x;
    scanf("%d", &x);

    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
    return DL;
}

// DLinkList DList_Tail_Insert(DLinkList& DL) {
//     DL = (DLinkList)malloc(sizeof(DNode));
//     // DL->next = NULL;
//     //最后赋给NULL，因为是尾插，
//     // 最后才能确定最后一个元素
//     DL->prior = NULL;

//     DNode *s, *r = DL;

//     ElemType x;
//     scanf("%d", &x);

//     while (x != 9999) {
//         s = (DNode*)malloc(sizeof(DNode));
//         s->data = x;

//         r->next = s;
//         s->prior = r;
//         r = s;

//         scanf("%d", &x);
//     }
//     r->next = NULL;
//     return DL;
// }

//按序号查找第i个结点
DNode* GetElem(DLinkList DL, int i) {
    int j = 1;
    if (0 == i)  //返回头结点
                 // 0 == i 常量写在前面，保证编译的通
        // 0 = i 时， 编译器会报错，保证编译的通
        return DL;
    if (i < 1)  //负值，啥也妹有
        return NULL;
    DNode* p = DL->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//将值为e的新结点插入到第i个位置
bool DList_Insert(DLinkList DL, int i, ElemType e) {
    //插入位置的前一个
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)
        return false;

    //待插入结点
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//删除第i个结点
bool DList_Delete(DLinkList DL, int i) {
    //DLinkList& DL不需要引用，因为不改变头部
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)
        return false;

    DNode* q = p->next;
    
    if (q == NULL)
        return false;

    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

int main() {
    DLinkList DL;

    // DList_Head_Insert(DL);
    // PrintList(DL);

    DList_Tail_Insert(DL);
    PrintList(DL);

    // DNode* p = GetElem(DL, 2);
    // printf("%d\n", p->data);

    // DList_Delete(DL, 2);
    // PrintList(DL);
}
