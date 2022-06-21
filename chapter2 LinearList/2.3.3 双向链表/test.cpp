#include <stdio.h>
#include <stdlib.h>
// TODO 爷抄的！
typedef int ElemType;

//相比单链表，增加了一个指向前驱的prior指针，因此
//按值查找和按位查找的操作与单链表相同。
//因为要对prior指针做出修改，关键是保证修改过程中不断链
//又双链表可以很方便的找到其前驱结点，因此
//插入 删除操作时间复杂度仅为O(1)
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

void PrintDList(DLinkList DL) {
    // DNode* p = DL->next;
    // while(p){
    //     printf("%6d", p->data);
    //     p = p->next;
    // }
    DL = DL->next;
    while (DL) {
        printf("%6d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}

//双向链表的头插法
DLinkList DList_Head_Insert(DLinkList& DL) {
    DL = (DNode*)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;

    DNode* s;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;

        s->next = DL->next;
        //插入第一个结点时，不需要这一步操作
        if (DL->next) {
            DL->next->prior = s;
        }
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

//按序号查找结点值 ： 查找第i个
DNode* GetElem(DLinkList DL, int i) {
    int j = 1;
    if (i == 0)
        return DL;  //返回头结点，头结点啥也妹有
    if (i < 1)      // i<0时，无效
        return NULL;
    DNode* p = DL->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//将新结点插入到第i个位置
bool DListInsert(DLinkList& DL, ElemType e, int i) {
    // 找到前一个结点
    DNode* p = GetElem(DL, i - 1);

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
bool ListDelete(DLinkList& DL, int i) {
    //找到第i-1个结点
    DNode* p = GetElem(DL, i - 1);
    if (p == NULL)  // TODO ？啥意思
        return false;

    DNode* q = p->next;

    if (q == NULL)
        return false;  // TODO

    p->next = q->next;  //断链  prior还没断

    if (q->next != NULL)
        // q->next != NULL 不是最后一个结点
        // 断掉前链
        //
        // q->next == NULL时删除，q是最后一个结点
        // 不会走这个if，直接释放结点
        q->next->prior = p;
    free(q);
    return true;
}

int main() {
    DLinkList DL;

    // DList_Head_Insert(DL);
    // PrintDList(DL);

    DList_Tail_Insert(DL);
    PrintDList(DL);

    //按序号查找
    DNode* p = GetElem(DL, 2);
    printf("%d", p->data);
}
